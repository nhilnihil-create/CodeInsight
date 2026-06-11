#include <iostream>
using namespace std;

void solve()
{
    char a; cin >> a;
    if (a-'a' >= 0) cout << "a" << endl;
    else cout << "A" << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    // input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}