#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;




int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int n, m;
    cin>>n>>m;
    dsu d(n);
    for (int i=0; i<m; i++) {
	int u,v;
	cin>>u>>v;
	--u; --v;
	d.merge(u,v);
    }

    auto g = d.groups();
    int cc = g.size();
    cout<<cc-1<<endl;
    
    
    return 0;
}
