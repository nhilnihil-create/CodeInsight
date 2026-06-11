#include <bits/stdc++.h>
using namespace std;

const int Maxn = 18;

int n;
int A[1 << Maxn + 1];
multiset <int> S[Maxn + 1];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 1 << n; i++)
        scanf("%d", &A[i]);
    sort(A, A + (1 << n));
    S[0].insert(A[(1 << n) - 1]);
    for (int i = (1 << n) - 2; i >= 0; i--) {
        int num = A[i];
        bool ok = false;
        for (int j = 0; j < n; j++) {
            multiset <int>::iterator it = S[j].upper_bound(num);
            if (it != S[j].end()) {
                S[j + 1].insert(*it);
                S[j].erase(it);
                S[j + 1].insert(num);
                ok = true;
                break;
            }
        }
        if (!ok) { printf("No\n"); return 0; }
    }
    printf("Yes\n");
    return 0;
}
