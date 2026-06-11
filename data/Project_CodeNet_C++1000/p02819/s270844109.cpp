#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pie 3.1415926536
#define pb push_back
#define N 1000000007
#define M 998244353
#define ff first
#define ss second
#define INF 1ll<<63 - 1
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define nrep(i,a,b) for(int i=a;i>=b;i--)
#define pl pair<ll,ll>
#define pi pair<int,int>
#define pll pair<pair<ll,ll>, ll> 
#define pii pair< int, pair<int,int> >
vector<ll> v;
ll seive[1000005];
void seiv(){
	for(int i =2; i*i<1000005; i++){
		if(!seive[i]){
			v.pb(i);
			for(int j = i*i ; j<1000005; j+=i)
			seive[j] = 1;
		}
	}
	rep(i,2,1000000){
		if(!seive[i]) v.pb(i);
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t,x,b,y,q,z,k,n,m;
    seiv();
    cin>>x;
    cout<<*lower_bound(v.begin(),v.end(),x);
}







