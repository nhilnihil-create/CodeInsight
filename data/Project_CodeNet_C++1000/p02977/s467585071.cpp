#include <bits/stdc++.h>

using namespace std;

int n;

void edge(int x, int y)
{
    cout << x << ' ' << y << '\n';
}

int main()
{
 //   freopen("input", "r", stdin);
    cin.sync_with_stdio(false); cin.tie(0);

    int i;
    cin >> n;

    if((n & (-n)) == n)
    {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";

    int x = -1, y = -1;

    if(n % 2 == 0)
    {
        x = (n & (-n));
        y = n ^ x; /// trebuie neaparat sa fie alaturate

        edge(n + y, n + (y^1));
        edge(n + (y^1), n + (x ^ 1));
        edge(n + (x ^ 1), n + x);
        edge(n + x, 1);
        edge(1, x^1);
        edge(x^1, x);
        edge(x, y);
        edge(y, y^1);
        edge(n, x);
        edge(2*n, y);
        edge(x, n+1);

        for(i=2; i<n; i += 2)
            if(i != x && i != y && i != (x ^ 1) && i != (y^1))
            {
                edge(n+(i^1), n+i);
                edge(n+i, 1);
                edge(1, i^1);
                edge(i^1, i);
            }
    }
    else
    {
        for(i=2; i<n; i += 2)
        {
                edge(n+(i^1), n+i);
                edge(n+i, 1);
                edge(1, i^1);
                edge(i^1, i);
        }
        edge(n+1, 2);
    }

    return 0;
}
