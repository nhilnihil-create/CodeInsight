#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T = int> void print(vector<T> v){for(auto a:v)cout<<a<<" ";cout<<endl;}

/*
*/

ll n,a[100010],s=0,s2=0,c=0;

void init(){
	cin>>n;
	rep(i,n)cin>>a[i];
}

int main(void){
	init();
	rep(i,n)s ^= a[i];
	rep(i,n)a[i] &= ~s;  // 興味深くないbitを消す
	ll rank=0;
	irep(i,60){
		int j;
		bool found=false;
		for(j=rank;j<n;j++){
			if(1 & (a[j]>>i)){
				break;
			}
		}
		if(j==n)continue;
		if(j>rank)swap(a[rank],a[j]);
		for(j=rank+1;j<n;j++) {
			if(1 & (a[j]>>i))a[j] ^= a[rank];
		}
		rank++;
	}
	rep(i,n)s2=max(s2,s2^a[i]);
	// rep(i,n){
	// 	rep(j,60)cerr<<(1 & (a[i]>>j))<<" ";
	// 	cerr<<endl;
	// }
	cout<<s+2*s2<<endl;
	return 0;
}