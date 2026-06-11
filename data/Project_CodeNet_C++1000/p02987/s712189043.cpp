#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Pxy = pair<double, double>;
using T = tuple<int, int, bool>;
const int INF = 1001001007;
const int mod = 1000000007;
//const int MOD = 998244353;
const ll inf = 1e18;
template <typename AT>
void printvec(vector<AT> &ar){
    rep(i,ar.size()-1) cout << ar[i] << " ";
    cout << ar[ar.size()-1] << endl;
}
template <typename Q>
void printvvec(vector<vector<Q>> &ar){
    rep(i,ar.size()){
        rep(j,ar[0].size()-1) cout << ar[i][j] << " ";
        cout << ar[i][ar[0].size()-1] << endl;
    }
}
template <typename S>
bool range(S a, S b, S x){
    return (a <= x && x < b);
}

struct you{
    int ma;
    set<P> st;
};

int main() {
    string s; cin >> s;
    int a = s[0] - 'A';
    int b = s[1] - 'A';
    int c = s[2] - 'A';
    int d = s[3] - 'A';
    if (a==b&&c==d&&a!=c){
        cout << "Yes" << endl;
        return 0;
    }
    if (a==c&&b==d&&a!=b){
        cout << "Yes" << endl;
        return 0;
    }
    if (a==d&&b==c&&a!=b){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}