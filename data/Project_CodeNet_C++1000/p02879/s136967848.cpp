#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    int A, B;

    cin >> A >> B;

    if(A<10 && B<10) {
        cout << A*B << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
    
}