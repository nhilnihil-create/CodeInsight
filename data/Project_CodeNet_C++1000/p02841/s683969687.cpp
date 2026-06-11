#include <bits/stdc++.h>

using namespace std;

int m1, d1, m2, d2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m1 >> d1 >> m2 >> d2;

    if(m1 != m2)
        cout << "1";
    else
        cout << "0";

    return 0;
}
