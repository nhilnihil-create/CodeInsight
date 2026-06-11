#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<bool> p(1000010,false);
    sort(all(a));
    int sum=0;
    rep(i,n){
        if(i!=n-1){
            if(a[i]==a[i+1]){
                p[a[i]]=true;
                continue;
            }
        }
        bool ans=true;
        for(ll j=1; j*j<=a[i]; j++){
            if(a[i]%j==0){
                if(p[j]) ans=false;
                if(p[a[i]/j]) ans=false;
            }
        }
        if(ans){
            sum++;
            // cout << a[i] << ' ';
        }
        p[a[i]]=true;
    }
    // cout << endl;

    cout << sum << endl;

    return 0;
}