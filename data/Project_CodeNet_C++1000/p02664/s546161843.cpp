#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    string S;
    cin >> S;
    char b = '-';
    for (auto e:S) {
        if(e=='?') cout << 'D';
        else  cout << e;
    }
    cout << endl;
}
