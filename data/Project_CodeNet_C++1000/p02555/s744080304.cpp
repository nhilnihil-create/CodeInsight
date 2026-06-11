#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int S;
    cin >> S;
    ll M = 1000000000+7;
    vector<ll> total(3, 0);
    ll n = 0;
    for(int i=3;i<=S;i++){
        n = (total[0] + 1) % M;
        total[0] = total[1];
        total[1] = total[2];
        total[2] = total[1] + n;
    }
    cout << n << endl;

    return 0;
}