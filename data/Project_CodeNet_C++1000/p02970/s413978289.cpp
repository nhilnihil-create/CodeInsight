#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, d;
    cin >> n >> d;
    cout << ceil(n/(d*2+1.)) << endl;
    return 0;
}
