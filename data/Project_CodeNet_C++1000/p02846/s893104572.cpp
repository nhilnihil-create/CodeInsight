#include <cstdio>
#include <algorithm>

using namespace std;

int T1, T2;
long long A1, A2, B1, B2;
long long da1, da2, db1, db2, diff1, diff2, suma, sumb;
long long ans;

int main()
{
    scanf("%d%d", &T1, &T2); scanf("%lld%lld%lld%lld", &A1, &A2, &B1, &B2);
    da1 = A1 * T1; da2 = A2 * T2; db1 = B1 * T1; db2 = B2 * T2;
    diff1 = da1 - db1; diff2 = da2 - db2; suma = da1 + da2; sumb = db1 + db2;
    if (suma == sumb)
    {
        printf("infinity\n");
        return 0;
    }
    if ((diff1 < 0 && sumb > suma) || (diff1 > 0 && suma > sumb))
    {
        printf("0\n");
        return 0;
    }
    ans = abs(diff1) / abs(diff1 + diff2);
    if (abs(diff1) % abs(diff1 + diff2) != 0)
    {
        printf("%lld\n", ans * 2 + 1);
    }
    else
    {
        printf("%lld\n", ans * 2);
    }
    return 0;
}
