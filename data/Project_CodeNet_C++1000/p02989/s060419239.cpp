#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    ll d[N];
    for(ll i = 0; i < N; i++) {
        cin >> d[i];
    }

    ll size = sizeof(d)/sizeof(*d);
    sort(d, d + size);
    cout << d[size / 2] - d[size / 2 - 1] << endl;

    return 0;
}