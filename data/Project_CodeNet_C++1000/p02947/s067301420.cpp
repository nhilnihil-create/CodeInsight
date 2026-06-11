#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

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
        ll x=e.second;
        //cout<<e.first<<" "<<x<<endl;
        ans+=x*(x-1)/2;
    }

    cout<<ans<<endl;
}

