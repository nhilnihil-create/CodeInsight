#include<iostream>
using namespace std;
int main()
{
    long long n, p = 1;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == 0)
        {
            cout << 0;
            return 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] <= 1000000000000000000 / p)
        {
            p = p * a[i];
        }
        else
        {
            cout << -1;
            return 0;
        }
    }
    cout << p;
    return 0;
}