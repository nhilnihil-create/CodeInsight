#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define FOR(i, m, n) for (int i = (int)m; i < (int)n; i++)

int main()
{
    int A, B;
    cin >> A >> B;
    cout << (A - 2 * B > 0 ? (A - 2 * B) : 0) << endl;
    return 0;
}