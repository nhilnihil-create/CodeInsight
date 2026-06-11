#include <iostream>
using namespace std;
long long n, a[200002];
int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    long long aim = a[1], sum = 0;
    for(int i = 2;i <= n;i++)
    {
        if(aim > a[i]) sum += aim - a[i];
        else if(aim < a[i]) aim = a[i];
    }
    cout << sum;
    return 0;
}
