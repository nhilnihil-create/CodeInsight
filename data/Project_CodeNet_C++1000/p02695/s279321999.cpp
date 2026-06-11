#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;

int n, m, q;
int a[50], b[50], c[50], d[50];
int A[50];

int dfs(int depth, int cur) {
    if (depth >= n) {
        int sum = 0;
        rep(i, q) {
            if (A[b[i] - 1] - A[a[i] - 1] == c[i]) {
                sum += d[i];
            }
        }
        return sum;
    }

    int best = 0;
    for (int i = cur; i <= m; i++) {
        A[depth] = i;
        int score = dfs(depth + 1, i);
        best = max(score, best);
    }
    return best;
}

int main()
{
    cin >> n >> m >> q;
    rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    put(dfs(0, 1));
    
    
    return 0;
}