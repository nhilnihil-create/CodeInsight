#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    ll X = N / 1.08;
    if((ll)(X * 1.08) == N) {
        cout << X << endl;
    } else if((ll)((X + 1) * 1.08) == N) {
        cout << X + 1 << endl;
    } else {
        cout << ":(" << endl;
    }
    
    return 0;
}