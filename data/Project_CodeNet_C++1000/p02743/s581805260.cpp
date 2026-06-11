#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b, c;
    cin >> a >> b >> c;

    long long d = c - a - b;

    if(d<0){
        cout << "No" << endl;
    }else{
        unsigned long long dd = d;
        unsigned long long aa = a, bb = b;

        if (4 * aa * bb < dd * dd) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

}