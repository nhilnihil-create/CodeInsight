#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int s = (a + b);
    if(s % 2) {
        cout << "IMPOSSIBLE";
    } else {
        cout << s / 2;
    }
    return 0;
}
