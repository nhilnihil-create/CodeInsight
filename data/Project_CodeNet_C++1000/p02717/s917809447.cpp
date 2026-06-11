#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int X, Y, Z;

int main() {
    cin >> X >> Y >> Z;
    int tmp = X;
    X = Y;
    Y = tmp;
    tmp = X;
    X = Z;
    Z = tmp;
    cout << X << " "<< Y << " " << Z << endl;
}