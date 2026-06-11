#include <iostream>
using namespace std;

int main(void)
{
    int n, m; cin >> n >> m;
    int ans = n * (n - 1) / 2 + m * (m - 1) / 2;
    cout << ans << endl;
}