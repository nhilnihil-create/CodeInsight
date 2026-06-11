#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x;
    cin >> x;
    long long int count = 0;
    if(x >= 500)
    {
        count += (x/500) * 1000;
        x %= 500;
    }
    if(x >= 5)
    {
        count += (x/5) * 5;
    }
    cout << count;
}
