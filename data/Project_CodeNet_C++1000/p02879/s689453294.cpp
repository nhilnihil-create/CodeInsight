#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI=acos(-1);
const int INF = numeric_limits<int>::max();

int main(){
    int a, b;
    cin >> a >> b;

    if (a >=10 || b >= 10) cout << -1 << endl;
    else cout << a * b << endl;

    return 0;
    
}