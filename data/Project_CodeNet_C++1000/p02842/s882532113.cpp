#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int k = n/1.08;
    int l = k+1;

//    cout << (int)(k*1.08) << "  " << (int)(l*1.08) << '\n';
    if ((int)(k*1.08) == n) cout << k << '\n';
    else if ((int)(l*1.08) == n) cout << l << '\n';
    else cout << ":(" << '\n';

    return 0;
}
