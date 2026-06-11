#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int a, b, c, k;
    cin >> a >> b >> c >> k;
    if(k <= a)
        cout << k;
    else if(k <= a + b)
        cout << a;
    else
        cout << a - (k - a - b);

}