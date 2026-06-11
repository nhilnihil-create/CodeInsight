#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string result;
    long long n;
    cin >> n;
    while (n > 0)
    {
        n--;
        result += char(97 + (n % 26));
        n /= 26;
    }
    reverse(result.begin(), result.end());
    cout << result;
    return 0;
}