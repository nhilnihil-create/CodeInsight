#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    string s;
    cin>>s;
    int n=s.size();
    reverse(all(s));

    vector<ll> v;
    v.push_back(0LL);
    ll p=1;
    ll pre=0;
    rep(i,n){
        ll x=s[i]-'0';
        x=(x*p)%2019;
        x=(x+pre)%2019;
        v.push_back(x%2019);
        p=(p*10)%2019;
        pre=x;
    }
    map<int,int> m;
    rep(i,n+1){
        m[v[i]]++;
    }

    ll ans=0;
    for(auto e : m){
        int num=e.second;
        if(num>1){
            ans+=(num*(num-1))/2;
        }
    }

    cout<<ans<<endl;
}
