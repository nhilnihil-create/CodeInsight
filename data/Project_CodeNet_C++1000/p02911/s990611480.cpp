#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long int;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    map<ll, ll> mp;

    for (size_t i = 0; i < Q; i++)
    {
        ll ai;
        cin >> ai;
        mp[ai - 1] += 1;
    }

    vector<ll> ans(N);
    for (size_t i = 0; i < N; i++)
    {
        if (K - Q + mp[i] > 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}