#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);++i)
#define FORR(i,L) for(auto& (i):(L))
#define ALL(a) ((a).begin()),((a).end())

int N;
ll S[1<<18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,1<<N) cin>>S[i];
	sort(S,S+(1<<N));
	multiset<int> T;
	FOR(i,(1<<N)-1) T.insert(S[i]);
	
	vector<int> V;
	V.push_back(S[(1<<N)-1]);
	FOR(i,N) {
		vector<int> W=V;
		
		FORR(v,V) {
			auto it=T.lower_bound(v);
			if(it==T.begin()) return _P("No\n");
			it--;
			W.push_back(*it);
			T.erase(it);
		}
		
		sort(ALL(W));
		reverse(ALL(W));
		swap(V,W);
	}
	_P("Yes\n");
	
}

int main()
{
    solve();

    return 0;
}