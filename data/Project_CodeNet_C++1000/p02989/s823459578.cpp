#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;
    vector<int> d(N);
    rep(i,N) cin >> d.at(i);
    sort(d.begin(), d.end());
    cout << d.at(N / 2) - d.at(N / 2 - 1) << endl;
}
