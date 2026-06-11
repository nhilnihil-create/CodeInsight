#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

string S;

int main() {
    cin >> S;
    if (S[0] == '7' || S[1] == '7' || S[2] == '7') cout << "Yes" << endl;
    else cout << "No" << endl;
}
