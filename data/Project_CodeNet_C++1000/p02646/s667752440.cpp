#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, ll> p;
 
#define MOD 1000000007

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;

    B = abs(A - B);
    A = 0;

    A += V * T;
    B += W * T;

    if(A >= B) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
}