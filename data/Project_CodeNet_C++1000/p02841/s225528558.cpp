// Template //
#include<bits/stdc++.h>
using namespace std;

// マクロ //
#define rep(i,N) for(int i = 0; i < N; i++)
#define all(x) x.begin(), x.end()
#define sort(x) sort(all(x))
#define cou(x) cout << x << endl
#define y() cout << "Yes" << endl
#define n() cout << "No" << endl
#define Y() cout << "YES" << endl
#define N() cout << "NO" << endl
#define x2(x) x * x

// 型エイリアス //
using lint = long long;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;

// 関数 //
int gcd(int a, int b) {
    int t;
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

// End of Template //

int main() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cou((a == c ? 0 : 1));


}