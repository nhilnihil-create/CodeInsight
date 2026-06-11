#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int codei[4] = {1, 1, -1, -1};
const int codej[4] = {-1, 1, -1, 1};

int main() {
    vector<int> num = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    ll K;
    cin >> K;
    cout << num.at(K-1) << endl;
}
