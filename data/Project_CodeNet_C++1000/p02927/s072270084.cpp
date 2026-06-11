#include <bits/stdc++.h>
#define fto(i, a, b) for (int i = a; i <= b; i++)
#define fdto(i, a, b) for (int i = a; i >= b; i--)
#define fi first
#define se second
#define NTLiinhh "bai1"
const int base = 1e9 + 7;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int m, d;
void Input()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //freopen(NTLiinhh".inp", "r", stdin);
    //freopen(NTLiinhh".out", "w", stdout);
    cin >> m >> d;
}

void Solve()
{
    int res=0;
    fto (i, 1, d)
        if (i%10>=2 && i/10>=2 && (i%10)*(i/10)<=m) ++res;
    cout << res;
}

int main()
{
    Input();
    Solve();
}
