#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;
// vector<vector<int>> data(3, vector<int>(4));

void solve(long long N, long long M, long long V, long long P, vector<long long> A){
	SORT(A);
	ll sum = 0, res = P;
	for (int i = N-P-1; i >= 0; i--) {
		ll nmp = A[N-P]+(max(0LL, M*max(0LL, V-(i+P))-sum)+(N-P-i)-1)/(N-P-i);
		// cout << i << ": " << nmp << " " << sum << endl;
		if (A[i] == A[i+1] || nmp <= A[i]+M) res++; else break;
		sum += A[N-P]-A[i];
	}
	cout << res << endl;
}

int main(){	
	long long M;
	long long P;
	long long V;
	long long N;
	scanf("%lld",&N);
	vector<long long> A(N-1+1);
	scanf("%lld",&M);
	scanf("%lld",&V);
	scanf("%lld",&P);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&A[i]);
	}
	solve(N, M, V, P, A);
	return 0;
}

