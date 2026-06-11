#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N = 0;
    cin >> N;
    vector<ll> A(N,0);
    ll sum = 0;
    for(ll i = 0; i < N; i++) {
        cin >> A.at(i);
        sum += A.at(i);
    }
    ll temp_sum = 0;
    ll min_sum = 1000000000000000000;
    for(ll i = 0; i < N; i++) {
        temp_sum += A.at(i)*2;
        min_sum = min(min_sum, abs(sum - temp_sum));
    }
    cout << min_sum << endl;


    return 0;
}