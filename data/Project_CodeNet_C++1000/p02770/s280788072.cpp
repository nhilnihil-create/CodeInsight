#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using ull = long long unsigned;
using P = pair<ll,ll>;
//const int 1001001001;
const int NMAX=8;
const ll MOD=1000000007;
const ll INF=1e18;
const int mod = 998244353;

int main(){
	ll k,q;
	cin>>k>>q;
	vector<ll> d(k);
	rep(i,k)cin>>d[i];
	rep(i,q){
		ll n1,x1,m1;
		cin>>n1>>x1>>m1;
		vector<ll> d1(k);
		ll sumd=0;
		ll sum0=0;

		vector<ll> d0(k,0);
		rep(i,k){
			d1[i]=d[i]%m1;
			sumd+=d1[i];
			if (d1[i]==0){
				d0[i]=1;
				sum0++;
			}
		}
		ll tot=n1-1;
		ll s=(n1-1)/k;
		ll a=(n1-1)%k;
		ll cnt=0;
		cnt+=s*sumd;
		rep(i,a){
			cnt+=d1[i];
		}
		cnt+=x1%m1;
		tot-=cnt/m1;
		//ここまでで繰り上がり処理、以下d=0のもの
		ll cnt0=0;
		cnt0+=sum0*s;
		rep(i,a){
			cnt0+=d0[i];
		}
		tot-=cnt0;
		cout<<tot<<endl;
	//	cout<<cnt<<'c'<<sum0<<'s'<<tot<<endl;

	}

}
