#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e3;


int n,m,q;
int a[maxn],b[maxn],c[maxn],d[maxn];
int best;
int arr[maxn];


int eval() {
    int cur=0;
    for (int i=0; i<q; i++) {
	if (arr[b[i]]-arr[a[i]]==c[i]) cur+=d[i];
    }
    return cur;
}

void dfs(int i, int lo) {
    if (i==n) {
	best=max(best,eval());
    } else {
	for (int v=lo; v<=m; v++) {
	    arr[i]=v;
	    dfs(i+1,v);
	}
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>m>>q;
    for (int i=0; i<q; i++) {
	cin>>a[i]>>b[i]>>c[i]>>d[i];
	a[i]--;
	b[i]--;
    }


    dfs(0,1);
    cout<<best<<endl;    
    return 0;
}
