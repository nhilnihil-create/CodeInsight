#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
const ld pi = 3.14159265358979323846;
 
int main() {
    ll n;
    cin>>n;
    vector<ll> v(n);
    rep(i,n){
        cin>>v[i];
    }
    ll ans=0;
    ll max_num=v[0];
    rep2(i,1,n){
        if (v[i]<max_num){
            ans+=max_num-v[i];
        }
        else{
            max_num=v[i];
        }
    }
    cout<<ans<<endl;

}