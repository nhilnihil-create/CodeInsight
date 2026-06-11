#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1010;


int n;
int id[maxn][maxn];
int k = 1;

vector<int> g[maxn*maxn];
int indeg[maxn*maxn];

int tot;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n;
    tot=n*(n-1)/2;
    
    for (int i=0; i<n; i++) {
	int prev = -1;
	for (int j=1; j<n; j++) {
	    int x; cin>>x;
	    --x;
	    if (!id[i][x]) {
		id[i][x]=id[x][i] = k;
		//cout<<"("<<i<<" "<<x<<"): "<<k<<endl;
		k++;
	    }
	    if (~prev) {
		g[prev].push_back(id[i][x]);
		indeg[id[i][x]]++;
	    }
	    prev = id[i][x];
	}
    }

    vector<int> Q;
    for (int i=1; i<k; i++) {
	if (indeg[i]==0) {
	    Q.push_back(i);
	}
    }

    int days=0;
    for (int i=0; i<int(Q.size()); ) {
	int len = Q.size();
	for (int j=i; j<len; j++) {
	    for (int x: g[Q[j]]) {
		if (--indeg[x] == 0) {
		    Q.push_back(x);
		}
	    }

	    i++;
	}
	days++;
    }



    if (int(Q.size()) == tot) out(days);
    out(-1);
    return 0;
}
