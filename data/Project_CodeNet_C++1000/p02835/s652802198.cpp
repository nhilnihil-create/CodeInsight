#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int A1, A2, A3, S;

    cin >> A1 >> A2 >> A3;

    S = A1 + A2 + A3;

    if(S>=22) {
        cout << "bust" << endl;
    } else {
        cout << "win" << endl;
    }

    return 0;
    
}