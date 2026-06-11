#include <bits/stdc++.h>
using namespace std;
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

int n;
vector<string> vec;

void dfs(string x, char y){
    if (x.size() == n){
        vec.push_back(x);
        return;
    }
    for(char c = 'a'; c <= y + 1; c++){
        dfs(x + c, (c == y + 1 ? y + 1: y));
    }
}

int main() {
    cin >> n;
    dfs("a", 'a');
    sort(all(vec));
    rep(i, vec.size()){
        cout << vec.at(i) << endl;
    }
}
