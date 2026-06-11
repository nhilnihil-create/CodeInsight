#include<iostream>
using namespace std;
int main()
{
    long long ans = 0, x, s = 100;
    cin >> x;
    while(s < x)
    {
        s = s + s / 100;
        ans++;
    }
    cout << ans;
    return 0;
}