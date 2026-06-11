#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const ll oo = 1e18 + 7;
const ll mod = 1e9 + 7, maxn = 2e5 + 10;  
const long double PI = acos(-1);
int cnt = 1, ps[maxn], sz[maxn];

int find(int x){
    if (x == ps[x]) return x;
    return ps[x] = find(ps[x]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);

    if (a == b) return;

    ps[a] = b;
    sz[b] += sz[a];
    cnt = max(cnt, sz[b]);
}

void init(){
    iota(ps, ps+maxn, 0);
    for (int i=0; i<maxn; i++) sz[i] = 1;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    init();

    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        uni(--a, --b);
    }

    cout << cnt << endl;
    return 0;   
}