#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int A, B, b;

    cin >> A >> B;

    b = B + B;

    if(A>b) {
        cout << A-b << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
    
}