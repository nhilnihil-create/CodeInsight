#include <iostream>
using namespace std;

int main(void)
{
    int n, m; cin >> n >> m;
    int a;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        sum += a;
    }
    int ans = max(-1, n-sum);
    cout << ans << endl;
}