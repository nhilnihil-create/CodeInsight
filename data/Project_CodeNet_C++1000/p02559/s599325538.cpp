//To compile : type "$     g++ test.cpp -std=c++14 -I .    "
#include <atcoder/all>
#include <bits/stdc++.h>
//#include <chrono>
//#pragma GCC optimize("Ofast")
using namespace std;
using namespace atcoder;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,Q,K,A,B;
string S;
typedef pair<ll, ll> P;
const ll INF = (1LL<<60);

int main() {
	cin>>N>>Q;
	fenwick_tree<ll> fw(N);
	rep(i,N){
		cin>>A;
		fw.add(i, A);
	}
	rep(_, Q){
		int t, u, v;
		cin>>t>>u>>v;
		if(t == 0){
			fw.add(u, v);
		}else{
			cout<<fw.sum(u, v)<<endl;
		}
	}
}