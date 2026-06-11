#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    rep(i, H) {
        rep(j, W) {
            if ((i < B) ^ (j < A)) cout << "0";
            else cout << "1";
        }
        cout << "\n";
    }
}