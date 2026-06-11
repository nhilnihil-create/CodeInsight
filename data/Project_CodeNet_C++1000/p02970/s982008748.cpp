#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define Graph vector<vector<ll>>
constexpr ll INF=(1ll<<60);
constexpr ll mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<typename T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}

int main(){
    ll n,d;cin>>n>>d;
    cout<<(n+(2*d+1)-1)/(2*d+1)<<endl;
	return 0;
}