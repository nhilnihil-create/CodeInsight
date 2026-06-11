#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;
const ll Inf = 1000000000000000000ll;

int n, k;
int P[Maxn];
int C[Maxn];
bool tk[Maxn];
vector <int> seq;
ll res = -Inf;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &P[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &C[i]);
    for (int i = 1; i <= n; i++) if (!tk[i]) {
        seq.clear();
        int cur = i;
        ll sum = 0;
        while (!tk[cur]) {
            sum += C[cur];
            seq.push_back(C[cur]);
            tk[cur] = true;
            cur = P[cur];
        }
        for (int i = 0; i < seq.size(); i++) {
            ll cand = 0;
            for (int j = 0; j < seq.size() && j + 1 <= k; j++) {
                cand += seq[(i + j) % int(seq.size())];
                if (sum > 0) res = max(res, cand + ll(k - j - 1) / ll(seq.size()) * sum);
                else res = max(res, cand);
            }
        }
    }
    cout << res << endl;
    return 0;
}
