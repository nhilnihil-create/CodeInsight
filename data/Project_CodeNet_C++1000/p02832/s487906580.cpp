#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////
int main(){
    int n;
    cin>>n;
    int a[200010];
    rep(i,n){
        cin >> a[i];
    }
    bool can = false;
    int cnt = 1,ans=0;
    rep(i,n){
        if(a[i]==cnt){
            can = true;
            cnt++;
        }
        else
            ans++;
    }
    if(can)
        cout << ans << endl;
    else
        cout << -1 << endl;

}