#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);

int k;
vll vec;
const ll X = 3234566667LL;

void dfs(string x){
    int size = x.size();
    if (size && stoll(x) > X) return;
    if (size) vec.push_back(stoll(x));
    rep(i, 10){
        if (size == 0){
            if (i != 0) dfs(x + to_string(i));
        }
        else if (abs((x[size - 1] - '0') - i) <= 1) dfs(x + to_string(i));
    }
}

int main() {
    cin >> k;
    dfs("");
    sort(all(vec));
    cout << vec[k - 1] << endl;
}