#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    int ans = 0;
    int shortage = B;
    while (shortage > 1)
    {
        ans++;
        shortage -= A - 1;
    }

    cout << ans << endl;

    return 0;
}