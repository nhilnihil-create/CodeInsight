#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

/*
*/

ll n,a[100010],ans=0;
map<ll,ll> m;
multiset<ll> s;

void init(){
	cin>>n;
	rep(i,n)cin>>a[i];
	rep(i,n)m[a[i]]=i;
}

int main(void){
	init();
	s.insert(-1);  // 番兵たち
	s.insert(-1);
	s.insert(n);
	s.insert(n);
	ireg(i,1,n){
		ll tmp=0,l2=-1,l=-1,r=n,r2=n;
		ll index = m[i];
		s.insert(index);
		auto itindex = s.find(index);
		auto itl = prev(itindex);
		l=*itl;
		itl--;
		l2=*itl;
		auto itr = next(itindex);
		r=*itr;
		itr++;
		r2=*itr;
		ans+=i*((l-l2)*(r-index)+(r2-r)*(index-l));
	}
	cout<<ans<<endl;
	return 0;
}