#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i,N) cin >> S.at(i);
    map<string, int> mp;
    rep(i,N) mp[S.at(i)] = 1;
    cout << mp.size() << endl;
}