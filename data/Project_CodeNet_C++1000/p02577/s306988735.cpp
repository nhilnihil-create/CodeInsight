#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

string S;

int main() {
    cin >> S;

    ll sum = 0;
    for (int i = 0; i < S.length(); i++) {
        sum += S[i] - '0';
    }

    cout << ((sum % 9 == 0) ? "Yes" : "No") << endl;

    return 0;
}
