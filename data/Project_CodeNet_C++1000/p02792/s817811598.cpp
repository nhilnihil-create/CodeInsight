#include <iostream>
using namespace std;
int main()
{
    int a[10][10] = {0}, x = 1;
    int n;
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        a[i % 10][i / x]++;
        if(i >= x * 10)
        {
            x *= 10;
        }
    }
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            ans += a[i][j] * a[j][i];
        }
    }
    cout << ans << endl;
    return 0;
}
