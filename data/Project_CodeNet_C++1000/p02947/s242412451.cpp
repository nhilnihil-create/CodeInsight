#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;
 
int main(){
    int n;
    cin>>n;
    map<string,ll> m;

    rep(i,n){
        string s;
        cin>>s;
        sort(all(s));
        m[s]++;
    }

    ll ans=0;
    for(auto e : m){
        ll tmp=e.second*(e.second-1)/2;
        ans+=tmp;
    }
    
    cout<<ans<<endl;
}