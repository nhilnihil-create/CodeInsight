#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<int(n); i++)
using namespace std;
typedef long long LL;

const int N=1e5+10;
int A[N], idx[N];
LL ans=0;
int main() {
	int n;
	scanf("%d", &n);
	REP(i,n) scanf("%d", &A[i]);
	REP(i,n) idx[A[i]]=i+1;

	set<int> s;
	s.insert(0);
	s.insert(n+1);
	for(int x=n; x>0; x--) { // permutation [1..n]
		int i=idx[x];
		LL c=0;
		{ // calculate ci
			if(s.size()==0) continue;
			int l1,l2,r1,r2; // l2 < l1 < i < r1 < r2
			auto it=s.upper_bound(i);
			auto it2=it;
			r1=*it;
			l1=*--it2;
			r2=(r1==n+1? r1:*++it);
			l2=(l1==0? 0:*--it2);
			// cout << l2 << ' ' << l1 << ' ' << r1 << ' ' << r2 << endl;;
			c=(LL)(l1-l2)*(r1-i)+(LL)(r2-r1)*(i-l1);
			s.insert(i);
		}
		ans+=x*c;
	}
	printf("%lld\n", ans);
	return 0;
}