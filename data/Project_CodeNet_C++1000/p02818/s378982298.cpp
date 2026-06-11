#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll A, B, K;
    cin >> A >> B >> K;

    if (K < A) {
        A -= K;
        K = 0;
    } else {
        K -= A;
        A = 0;
    }
    if (K < B) {
        B -= K;
    } else {
        B = 0;
    }
    cout << A << " " << B << endl;
    
}

