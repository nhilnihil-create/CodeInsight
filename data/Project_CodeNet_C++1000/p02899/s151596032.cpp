#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    ll A[N];
    for(ll i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        A[tmp - 1] = i + 1;
    }

    for(ll i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}