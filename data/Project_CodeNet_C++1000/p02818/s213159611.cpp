#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
#define _GLIBCXX_DEBUG
#define IO_STREAM cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(int i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
const ll INF = 1000000000000000;
const ll MOD = 1000000007;
const double PI = acos(-1);
//||
#define DBG(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl
//DBG("","","","");

signed main(){
	IO_STREAM;
	ll A,B,K;
	cin>>A>>B>>K;
	if(A>K){
		A-=K;
	}
	else if(A==K){
		A=0;
	}
	else{
		B-=K-A;
		A=0;
		if(B<0) B=0;
	}
	cout<<A<<endl;
	cout<<B<<endl;
	return 0;
}
