#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define INF 1000000000

int main() {
    string in;
    cin >> in;
    int n=0;
    rep(i,3) n += bool(in.at(i)=='R');
    if (in.at(1) == 'S') cout << bool(n>=1) << endl;
    else cout << n << endl;
}