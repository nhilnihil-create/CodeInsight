#include <iostream>
typedef long long ll;
#define mod 998244353
using namespace std;
ll power(int n, int m){
    ll ans = 1LL;
    for(int i=0;i<m;i++){
        ans *= n;
        ans %= mod;
    }
    return ans;
}
int main(void)
{
    int n; cin >> n;
    int d[100001];
    for(int i=0;i<100001;i++) d[i] = 0;
    bool flag = false;
    int size = 0;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        if(i==0&&x!=0) flag = true;
        if(d[x]==0) size++;
        d[x]++;
    }
    ll ans = 1;
    if(d[0]!=1) flag = true;
    else{
        for(int i=0;i<size-2;i++){
            if(d[i+1]==0||d[i+2]==0){
                flag = true; break;
            }
            ans *= power(d[i+1],d[i+2]);
            ans %= mod;
        }
    }
    if(flag) cout << 0 << endl;
    else cout << ans << endl;
}
