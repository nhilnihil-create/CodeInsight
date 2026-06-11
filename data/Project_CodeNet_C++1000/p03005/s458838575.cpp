#include <bits/stdc++.h>
using namespace std;
int _I(){ int x ; scanf("%d", &x); return x; }
void solve()
{
    int n = _I();
    int k = _I();
    if( k == 1 )
    {
        printf("0\n");
        return;
    }
    printf("%d\n", n-k );
}
int main()
{
    solve();
    return 0;
}
