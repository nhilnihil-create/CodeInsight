#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

double N, X, T;

int main() {
    cin >> N >> X >> T;
    
    cout << int(ceil(N/X) * T) << endl;

    return 0;
}
