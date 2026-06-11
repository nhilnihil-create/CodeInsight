#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int K, A, B;

int main() {
    cin >> K >> A >> B;
    if (A%K == 0) {
        cout << "OK" << endl;
    } else {
        if ((K * (A/K + 1)) <= B) {
            cout << "OK" << endl;
        } else {
            cout << "NG" << endl;
        }
    }

}