#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
#define _GLIBCXX_DEBUG
#define IO_STREAM cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(ll i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define INF 1000000000000000LL
const ll MOD = 1000000007;
const double PI = acos(-1);
//||
#define DBG(a,b,c,d) //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl
//DBG("","","","");

signed main(){
	IO_STREAM;
	int N,K;
	cin>>N>>K;
	vi A(N);
	rep(i,0,N){
		cin>>A[i];
	}
	rep(cnt,0,K){
		vi B(N+1);
		rep(i,0,N){
			int st,ed;
			st=max((int)(i-A[i]),0);
			ed=min((int)(i+A[i]+1),N);
			B[st]++;
			B[ed]--;
		}
		rep(i,0,N){
			B[i+1]+=B[i];
		}
		if(A==B) break;
		A=B;
		B[N]=0;
	}
	rep(i,0,N){
		cout<<A[i]<<' ';
	}
	return 0;
}
