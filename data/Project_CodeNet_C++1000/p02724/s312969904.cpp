#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(int x)
{
    if(x / 500)
        return solve(x % 500) + (x / 500) * 1000;
    else if(x / 5)
        return solve(x % 5) + (x / 5) * 5;
    else
        return 0;
}


int main()
{
    int x;
    cin >> x;

    cout << solve(x) << "\n";
    return 0;
}