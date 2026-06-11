#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, ans[100001];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        ans[a] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
}