#include <iostream>
using namespace std;
int arr[1000005] = {0};
int main()
{
    int n;
    long long res = 0;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i; j <= n; j += i)
        {
            ++arr[j];
        }
        res += arr[i];
    }
    cout << res;
}