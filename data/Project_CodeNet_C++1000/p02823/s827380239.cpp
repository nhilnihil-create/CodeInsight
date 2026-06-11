#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, A, B;
    cin >> N >> A >> B;
    if(A%2 == B%2) cout << llabs(A-B) / 2 << endl;
    else
    {
        ll na = N - A;
        ll nb = N - B;
        ll a = A-1;
        ll b = B-1;
        cout << min(na, min(nb, min(a, b))) + 1 + llabs(A-B) / 2 << endl;
    }
    

    return 0;
}
