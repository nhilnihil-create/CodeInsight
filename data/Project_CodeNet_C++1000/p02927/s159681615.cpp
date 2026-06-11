#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define TTT "BAI1"
#define maxn
using namespace std;
int m, d, res = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> d;
    fi(i, 1, m)
    fi(j, 1, d)
    {
        int x = j / 10;
        int y = j % 10;
        if(x * y == i && x >= 2 && y >= 2) res++;
    }
    cout << res;
}
