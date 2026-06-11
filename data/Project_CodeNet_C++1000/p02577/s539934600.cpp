#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int sum = 0;
    for (char c : s) sum += (int) (c - '0');
    if (sum % 9) cout << "No" << '\n';
    else cout << "Yes" << '\n';
    return 0;
}