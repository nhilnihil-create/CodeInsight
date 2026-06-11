#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    ll N, K, S;
    vector<ll>ans;

    cin >> N >> K >> S;

    for (int i = 0; i < K; i++) {
        ans.push_back(S);
    }

    for (int i = 0; i < N-K; i++) {
        if (S == 1000000000) {
            ans.push_back(S-1);
        } else {
            ans.push_back(1000000000);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

