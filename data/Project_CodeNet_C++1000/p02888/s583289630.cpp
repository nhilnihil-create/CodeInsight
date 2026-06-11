#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    int a[n];
    for(int i = 0;i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 2; i < n; i++)
    {
        for(int j = 0, k = i - 1; j < k;)
        {
            if(j < k && a[j] + a[k] > a[i])
            {
                ans += k - j;
            }
            if(a[j] + a[k] <= a[i])
            {
                j++;
            }
            else
            {
                k--;
            }
            
        }
    }
    cout << ans << endl;
    return 0;
}
