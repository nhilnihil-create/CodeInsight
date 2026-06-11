#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(ll (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll=long long;
constexpr ll MOD=1e9+7;

int main()
{
	int N;
	cin>>N;
	vector<int> A(N), cnt(100000,0);
	rep(i,N)cin>>A[i];

	ll res = count(A.begin(), A.end(), 0);
	if(res>3){
		cout<<0<<endl;
		return 0;
	}
	vector<int> base = {0,3,6,6};
	res = base[res];
	rep(i,N){
		if(A[i]>0){
			(res *= cnt[A[i]-1])%=MOD;
		}
		cnt[A[i]-1]--;
		cnt[A[i]]++;
	}
	cout<<res<<endl;
	return 0;
}
