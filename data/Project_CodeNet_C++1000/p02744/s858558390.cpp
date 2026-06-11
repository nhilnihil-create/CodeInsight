#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;
    vector<vector<pair<string, char>>> ans(11);
    ans.at(1).push_back(make_pair("a", 'b'));
    for (int i = 2; i <= 10; ++i) {
        for (auto x : ans.at(i-1)) {
            rep(j,x.second-'a'+1) {
                string tmp = x.first;
                tmp.push_back('a' + j);
                if (x.second - 'a' == j) ans.at(i).push_back(make_pair(tmp, x.second + 1));
                else ans.at(i).push_back(make_pair(tmp, x.second));
            }
        }
    }
    for (auto x : ans.at(N)) cout << x.first << endl;
}
