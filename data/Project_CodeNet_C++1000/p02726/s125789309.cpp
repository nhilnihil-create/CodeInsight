#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    --X;
    --Y;
    vector<int> count(N-1,0);
    rep(i,N) {
        for(int j = i + 1; j < N; ++j) {
            int dist = min(j-i,abs(X-i)+abs(Y-j)+1);
            ++count.at(dist-1);
        }
    }
    rep(i,N-1) cout << count.at(i) << endl;
}
