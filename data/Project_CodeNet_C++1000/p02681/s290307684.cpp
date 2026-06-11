#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

string S, T;

int main() {
    cin >> S >> T;
    int n = S.size();
    if (T.size()== n+1 && T.substr(0,n) == S) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
