#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long

int main() {
    using namespace std;
    ll n, k;
    cin >> n >> k;
    vector<int> A(n), F(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> F[i];
    sort(A.begin(), A.end());
    sort(F.begin(), F.end());
    reverse(F.begin(), F.end());

    ll result = 0;
    for(int i = 0; i < n; i++)
        result = max(result, (ll)A[i] * F[i]);

    ll a = 0, b = result + 1, c;
    while(a < b) {
        c = (a + b) / 2;

        ll x = 0;
        for(int i = 0; i < n; i++)
            x += max((ll)0, A[i] - c / F[i]);

        if(x <= k)
            b = c;
        else
            a = c + 1;
    }

#if 0
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i++)
        cout << F[i] << " ";
#endif

    cout << a << "\n";
    return 0;
}
