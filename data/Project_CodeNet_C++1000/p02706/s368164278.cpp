#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, M;
    cin >> N >> M;
    int sum = 0;
    rep(i, M) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        if (sum > N) {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << N - sum << endl;
    return 0;
}
