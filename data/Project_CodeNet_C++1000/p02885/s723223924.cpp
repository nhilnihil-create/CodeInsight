#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int A, B; cin >> A >> B;
    cout << max(0, A - 2 * B) << endl;
    return 0;
}