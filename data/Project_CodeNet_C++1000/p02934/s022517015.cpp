#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n, a[1000];
    double s = 0, p = 1;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        p = p * a[i];
    }
    for(int i = 0; i < n; i++)
    {
        s = s + p/a[i];
    }
    cout << setprecision(16) << p / s;
    return 0;
}