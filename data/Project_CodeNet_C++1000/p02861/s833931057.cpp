#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N), order;
    int cnt = 0;
    rep(i,N) cin >> x.at(i) >> y.at(i);
    rep(i,N) order.push_back(i);
    long double sum = 0;
    do {
        rep(j,N-1) {
            long double diffx = x.at(order.at(j+1)) - x.at(order.at(j));
            long double diffy = y.at(order.at(j+1)) - y.at(order.at(j));
            sum += sqrt(diffx*diffx + diffy*diffy);
        }
        ++cnt;
    } while (next_permutation(order.begin(), order.end()));
    sum /= cnt;
    cout << fixed << setprecision(8) << sum << endl;
}

