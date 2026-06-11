#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, a, res;
    cin >> h >> a;

    if(h % a == 0)
        res = h / a;
    else res = h / a + 1;

    cout << res << "\n";
    return 0; 
}
