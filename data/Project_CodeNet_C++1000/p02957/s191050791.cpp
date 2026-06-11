#include <bits/stdc++.h>
using namespace std;
#define loop(i,n) for (int i =0;i<(n);++i)
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    ll A, B; cin >> A >> B;
    if (A % 2 == B % 2) {
        cout << (A+B) / 2 << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
 
    return 0;
}