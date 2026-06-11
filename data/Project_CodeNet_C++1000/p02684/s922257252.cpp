#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<stack>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> lpii;
typedef unsigned long long ull;
const double eps = 1e-8;
const double pi = acos(-1.0);
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 2e5 + 10;
int vis[N];
int a[N];
int l1, l2, l;
int n;
ll k;
int d[N];
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    vis[1] = 1;
    l = 0;
    a[l] = 1;
    int x = d[1];
    while(!vis[x]) {
        vis[x] = 1;
        a[++l] = x;
        x = d[x];
    }

    for(int i = 0; i <= l; i++) {
        if(a[i] == x) {
            l1 = i;
            break;
        }
    }
    if(k <= 1ll * l1) {
        cout << a[(int) k] << endl;
    }
    else {
        k -= (1ll *l1);
        k %= (l - l1 + 1);
        cout << a[(int)k + l1] << endl;
    }
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("std1.in","r",stdin);
#endif
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    //scanf("%d", &t);
    while(t--) {
        solve();
    }
    return 0;
}
