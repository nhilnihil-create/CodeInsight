#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

int N,M,V,p;
int A[100005];
signed main() {
	cin>>N>>M>>V>>p;
	rep(i,N)cin>>A[i];
	sort(A,A+N,greater<>());
	int ok=0,ng=N;
	while(ng-ok>1){
		int mid=(ok+ng)/2;
		if(mid<p){ok=mid;continue;}
		if(A[mid]<A[p-1]-M){ng=mid;continue;}
		int sum=(p-1)*M+(N-mid)*M;
		for(int i=p-1;i<mid;i++){
			sum+=A[mid]+M-A[i];
		}
		if(sum>=V*M)ok=mid;
		else ng=mid;
	}
	cout<<ok+1<<endl;
}

