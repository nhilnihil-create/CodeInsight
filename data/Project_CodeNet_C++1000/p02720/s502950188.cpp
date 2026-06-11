#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

set<ll> kouho;

void solve(string now){
    if(now.size() <= 10){
        ll a = stoll(now);
        kouho.insert(a);
        for(int i = 0; i < 10; i++){
            int d = now[now.size()-1]-'0';
            if(abs(d-i) <= 1){
                solve(now + toString(i));
            }
        }
    }
}

int main(){
    ll K;
    cin >> K;
    for(ll i = 1; i < 10; i++){
        solve(toString(i));
    }
    vector<ll> v(kouho.begin(), kouho.end());
    cout << v[K-1] << endl;
}