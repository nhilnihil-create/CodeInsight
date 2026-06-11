#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n, q;
int par[maxn];
int siz[maxn];

int parent(int x) {
    return par[x]==x ? x : par[x]=parent(par[x]);
}

void join(int x, int y) {
    x = parent(x);
    y = parent(y);
    if (x==y) return;
    if (siz[x]<siz[y]) swap(x,y);
    siz[x] += siz[y];
    par[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>q;
    for (int i=0; i<n; i++) {
	siz[i]=1;
	par[i]=i;
    }
    while (q--) {
	int t;
	cin>>t;
	int u,v;
	cin>>u>>v;
	if (t==0) {
	    join(u,v);
	} else {
	    cout<<(parent(u)==parent(v))<<"\n";
	}
    }
    
    
    return 0;
}
