#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define Graph vector<vector<ll>>
#define INF (ll)(1ll<<60)
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
	ll a,b;cin>>a>>b;
	if((a+b)%2){
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	cout<<(a+b)/2<<endl;
	return 0;
}