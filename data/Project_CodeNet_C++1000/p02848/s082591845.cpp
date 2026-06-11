#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define P pair<ll,ll>
#define Graph vector<vector<P>>
#define fi first
#define se second
constexpr ll mod=1000000007;
constexpr ll INF=(1ll<<60);
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<typename T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}

int main(){
    ll n;cin>>n;
    string s;cin>>s;
    ll ss=s.size();
    vector<ll> num(ss);
    rep(i,ss){
        num[i]=(ll)(s[i]-'A');
    }

    rep(i,ss){
        cout<<(char)('A'+((num[i]+n)%26));
    }
    cout<<endl;

    return 0;
}