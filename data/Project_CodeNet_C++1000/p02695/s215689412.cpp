#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int cat[11][11][11];

int v[11];

int mx, sum;

void bkt(int k)
{
    if(k == n + 1)
    {
        mx = max(mx, sum);
        return;;
    }

    for(int i = v[k - 1]; i <= m; i ++)
    {
        v[k] = i;
        int ant = sum;

        for(int j = 1; j < k; j ++)
            sum += cat[j][k][i - v[j]];

        bkt(k + 1);

        sum = ant;

    }
}

int main()
{
    cin >> n >> m >> q;

    for(int i = 1; i <= q; i ++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cat[a][b][c] += d;

    }

    v[1] = 1;

    bkt(2);

    cout << mx << "\n";

    return 0;
}
