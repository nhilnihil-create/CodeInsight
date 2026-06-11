#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll A, B, V, W, T;
    cin >> A >> V;
    cin >> B >> W;
    cin >> T;

    ll length = abs(A-B);
    if (length <= (V-W)*T ){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}