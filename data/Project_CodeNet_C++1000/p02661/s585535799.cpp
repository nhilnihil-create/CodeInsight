#include <bits/stdc++.h>

using namespace std;

#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1, v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1, v2, v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1, v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1, v2, v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define endl '\n'

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;


void run_case() {
    int n;
    cin >> n;
    vi a(n), b(n);
    loop(i, n)cin >> a[i] >> b[i];
    sort(ALL(a));
    sort(ALL(b));
    if (n % 2 == 0) {
        cout << (b[n / 2] + b[n / 2 - 1]) - (a[n / 2] + a[n / 2 - 1]) + 1 << endl;
    } else {
        cout << b[n / 2] - a[n / 2] + 1 << endl;
    }
}

int main() {

#ifndef ONLINE_JUDGE
//    freopen("in.in", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    while (T--)run_case();

    return 0;
}
