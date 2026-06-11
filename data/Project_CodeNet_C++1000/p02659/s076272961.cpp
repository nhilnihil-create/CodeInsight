#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
typedef pair<int, int> P;


int main() {
    ll a;
    string b;
    cin >> a >> b;
    b.replace(b.size() - 3, 1, "");
    ll bb = stoi(b);
    cout << a * bb / 100 << endl;
    return 0;
}
