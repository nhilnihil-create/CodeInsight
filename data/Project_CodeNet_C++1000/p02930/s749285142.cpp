#include <bits/stdc++.h>
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define FORUL(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define FORULE(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#if defined(_MSC_VER) || __cplusplus > 199711L
#define AUTOVAR(newvar,v) auto newvar = (v)
#else
#define AUTOVAR(newvar,v) __typeof(newvar) r = (v)
#endif
#define PB(x) push_back(x)
#define MP(x,y) make_pair((x),(y))
#define MEMSET(m,v) memset(m,v,sizeof(m))

typedef long long				 ll;
typedef unsigned long long		ull;

#define DEBUG 1

#if DEBUG
#define DOUT cout<<"["<<__LINE__<<"]:"
#else
#define DOUT 0 && cout
#endif

using namespace std;

#define MAX_N 500


int N;
vector<int> edges[MAX_N];

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(false);

	cin >> N;

	double log2 = log(2);
	double logN = log(N);

	int maxlevel = (int)ceil(logN/log2);
	
	FOR(i,N) {
		edges[i].resize(N);
	// 	FOR(j,N) {
	// 		edges[i][j] = -1;
	// 	}
	}

	FOR(i,N) {
		FOR(j,N) {
			if(i==j) {
				continue;
			}
			if(edges[i][j]>0) {
				continue;
			}
			int exor = i^j;
			for(int level = 0; level<maxlevel; level++) {
				if ((0x01<<level) & exor) {
					edges[i][j] = level+1;
					edges[j][i] = level+1;
					break;
				}
			}
		}
	}

	FOR(i,N) {
		for(int j=i+1; j<N; j++) {
			cout << edges[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}


