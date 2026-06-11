#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A.at(i);
    map<int, int> mp;
    long ans;
    long sum = 0;

    rep(i,N) ++mp[A.at(i)];
    for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
        long n = iter->second;
        if (n >= 2) {
            sum += (n*n - n) / 2;
        }
    }
    rep(i,N) {

        if (mp[A.at(i)] >= 2) {
            ans = sum - (mp[A.at(i)] - 1);
        } else {
            ans = sum;
        }
        cout << ans << endl;
    }
}
