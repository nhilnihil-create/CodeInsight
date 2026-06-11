#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n,m,k;
int a[maxn];
int b[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>m>>k;
    for (int i=1; i<=n; i++) {
	cin>>a[i];
    }
    for (int i=1; i<=m; i++) {
	cin>>b[i];
    }

    int ans = *min_element(a+1,a+1+n) + *min_element(b+1,b+1+m);

    while (k--) {
	int x, y, c;
	cin>>x>>y>>c;
	ans = min(ans, a[x]+b[y]-c);
    }

    cout<<ans<<endl;    
    return 0;
}
