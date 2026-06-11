#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b;
    if((a+b)%2)cout << "IMPOSSIBLE";
    else     cout << (a+b)/2;
}
