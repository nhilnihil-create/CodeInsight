#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T1, T2;
ll A1, A2;
ll B1, B2;

int main()
{
    cin >> T1 >> T2;
    cin >> A1 >> A2; A1 *= T1; A2 *= T2;
    cin >> B1 >> B2; B1 *= T1; B2 *= T2;
    if (A1 + A2 == B1 + B2) { printf("infinity\n"); return 0; }
    if (A1 + A2 > B1 + B2) { swap(A1, B1); swap(A2, B2); }
    if (A1 > B1) {
        ll r = (A1 - B1) / (B1 + B2 - A1 - A2);
        ll res = 2ll * r;
        if ((A1 - B1) % (B1 + B2 - A1 - A2)) res++;
        cout << res << endl;
    } else printf("0\n");
    return 0;
}
