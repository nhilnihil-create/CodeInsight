#include <bits/stdc++.h>

using namespace std;

int x, a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> a;

    if(x < a)
        cout << "0";
    else
        cout << "10";

    return 0;
}
