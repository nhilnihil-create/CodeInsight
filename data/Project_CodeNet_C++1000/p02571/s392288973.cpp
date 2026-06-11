#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
const ld pi = 3.14159265358979323846;
const ll mod = 1000000007;
const ll inf = 1LL << 60;
 
int main() {
    string s,t;
    cin>>s>>t;
    ll ans=t.size();
    rep(i,s.size()-t.size()+1){
        ll cnt=0;
        rep(j,t.size()){
            if (s[i+j]!=t[j]){
                cnt+=1;
            }
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
}