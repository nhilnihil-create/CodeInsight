#include<bits/stdc++.h>
using namespace std;
#define LL long long int

int main() {
    LL a, b, c;

    cin >> a >> b >> c;

    LL lhs = a * b * 4;
    LL rhs = (c - a - b)*(c - a - b);

    if (lhs < rhs && c - a - b >= 0)
        cout << "Yes\n";
    else
        cout << "No\n";
}
