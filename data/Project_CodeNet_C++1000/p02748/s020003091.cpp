#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, M;
    cin >> A >> B >> M;
    vi a(A), b(B);
    rep(i, A) cin >> a[i];
    rep(i, B) cin >> b[i];
    vi x(M), y(M), c(M);
    rep(i, M) cin >> x[i] >> y[i] >> c[i];

    int min_a = a[0], min_b = b[0];
    repm(i, 1, A)
    {
        min_a = min(min_a, a[i]);
    }
    repm(i, 1, A)
    {
        min_b = min(min_b, b[i]);
    }
    int minval = min_a + min_b;
    rep(i, M)
    {
        minval = min(minval, a[x[i] - 1] + b[y[i] - 1] - c[i]);
    }
    
    // int minval = a[0] + b[0];
    // rep(i, A)
    // {
    //     rep(j, B)
    //     {
    //         int max_dis = 0;
    //         rep(k, M)
    //         {
    //             if (x[k] - 1 == i && y[k] - 1 == j)
    //             {
    //                 max_dis = max(max_dis, c[k]);
    //             }
    //         }
    //         minval = min(minval, a[i] + b[j] - max_dis);
    //     }
    // }

    cout << minval << endl;

    return 0;
}