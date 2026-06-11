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
long long k;
long long sA[maxn],sB[maxn];
void Solve(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;++i){
        int a;
        cin >> a;
        sA[i] = sA[i - 1] + a;
    }
    for(int i = 1;i <= m;++i){
        int b;
        cin >> b;
        sB[i] = sB[i - 1] + b;
    }
    int maxx = 0;
    for(int i = 0;i <= n;++i){
        if(sA[i] > k) break;
        int pos = upper_bound(sB + 1,sB + m + 1,k - sA[i]) - sB - 1;
        maxx = max(pos + i,maxx);
    }
    cout << maxx;
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
