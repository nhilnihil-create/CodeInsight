#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

#ifdef LOCAL
#define show(x) cerr << "LINE" << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
#endif

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);		//DON'T USE scanf/printf/puts !!
	cout << fixed << setprecision(20);
	
	int N;
	cin >> N;
	if(__builtin_popcount(N) == 1){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	auto ADD = [&](int x,int y){
		cout << x << " " << y << endl;
	};
	rep(t,(N-1)/2){
		int a = t*2+2, b = a+1;
		ADD(1,a);
		ADD(a,b);
		ADD(1,b+N);
		ADD(b+N,a+N);
	}
	ADD(3,1+N);
	if(N%2 == 0){
		ADD(N,N-1+N);
		ADD(N+N,(N-1)^1^N);
	}
}
