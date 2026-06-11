#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    auto f = [&](int u){
        int v = u + n;
        return v;
    };

    if ((n & (n - 1)) == 0){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    cout << 1 << " " << 2 << endl;
    cout << 1 << " " << 3 << endl;
    cout << 3 << " " << f(2) << endl;
    cout << f(3) << " " << 2 << endl;
    cout << f(1) << " " << f(3) << endl;

    for (int i = 4; i + 1 <= n; i += 2){
        cout << 1 << " " << i << endl;
        cout << 1 << " " << i + 1 << endl;
        cout << i << " " << f(i + 1) << endl;
        cout << i + 1 << " " << f(i) << endl;
    }

    if (n % 2 == 0){
        int a = 1 << __lg(n);
        int b = n - a + 1;

        cout << n << " " << a << endl;
        cout << f(n) << " " << b << endl;
    }

    return 0;
}