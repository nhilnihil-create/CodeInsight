// https://atcoder.jp/contests/abc092/tasks/abc092_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A), b(B);
    for (int i = 0; i < A; i++)
        cin >> a[i];
    for (int i = 0; i < B; i++)
        cin >> b[i];
    int ans = (*min_element(a.begin(), a.end())) + (*min_element(b.begin(), b.end()));
    for (int i = 0; i < M; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        --x;
        --y;
        ans = min(ans, a[x] + b[y] - c);
    }

    cout << ans << endl;
    return 0;
}
