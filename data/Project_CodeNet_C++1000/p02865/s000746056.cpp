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
using vli = vector<lint>;
using vc = vector<char>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using msi = map<string, int>;

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

double distance(pii a, pii b) {
    double dist;
    dist = sqrt(x2(a.first - b.first) + x2(a.second - b.second));
    return dist;
}

// End of Template //



int main() {

    int N;
    cin >> N;

    cou((N - 1) / 2);

}