#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
    long long A;
    scanf("%lld", &A);
    string B;
    cin >> B;
    B.erase(B.size() - 3, 1);
    ll b = stoll(B);
    cout << A * b / 100 << endl;

    return 0;
}
