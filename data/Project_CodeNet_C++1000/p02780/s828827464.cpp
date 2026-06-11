#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double pos[1001];
    double total = 0, sum = 0, maxi = 0;
    for(int i = 1; i <= 1000; i++)
    {
        total += i;
        pos[i] = total / i;
    }
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i < k)
        {
            sum += pos[a[i]];
        }
    }
    maxi = sum;
    for(int i = k - 1; i < n; i++)
    {
        if(i != k - 1)
        {
            sum += pos[a[i]];
        }
        if(sum >= maxi)
        {
            maxi = sum;
        }
        sum -= pos[a[i - k + 1]];
    }
    cout << fixed << setprecision(1) << maxi << endl;
    return 0;
}