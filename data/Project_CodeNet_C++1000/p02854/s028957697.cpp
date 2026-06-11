#include <bits/stdc++.h>
using namespace std;
using ll = long long; // ll は long long　と同じとする。
int main() {
    ll N;
    cin >> N;
    vector <ll> A(N);
    ll sum = 0;
    for(ll i = 0; i < N; i++){
        cin >> A.at(i);
        sum += A.at(i);
    }
    ll S = sum;
    ll num = 0;
    for(int i = 0; i < N; i++){
        num += A.at(i);
        S = min(S , abs(num - (sum - num)));
    }
    cout << S << endl;
    return 0;
}
