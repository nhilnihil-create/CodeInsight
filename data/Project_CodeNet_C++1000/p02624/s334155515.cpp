// VU TRUONG AN
#include <bits/stdc++.h>
#define F first
#define S second
#define maxn 200005
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define pi acos(-1)
#define bit(p,x) ((x>>p) & 1)
#define Task "CF"
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int base = 100003;
const long long MM = 1ll * MOD * MOD;

int n,m;

long long ans = 0;

void Solve(){
    cin >> n;
    for(int i = 1;i <= n;++i){
        int pos = n / i;
        long long res = 1ll * pos * (pos + 1) / 2;
        ans += res * i;
    }
    cout << ans;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
#endif
    int test = 1;
//    cin >> test;
    while(test--)
        Solve();
}
