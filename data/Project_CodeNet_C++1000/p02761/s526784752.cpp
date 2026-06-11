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

int solve(int a, int b){
    while(b>0){
        a*=10;
        b--;
    }
    return a;
}
int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<int,char>> p(M);
    rep(i,M){
        int s;
        char c;
        cin >> s >> c;
        s--;
        p[i] = {s,c};
    }
    int s = solve(1,N-1);
    int g = solve(1,N);
    if(N==1) s=0;
    for(int i = s; i < g; i++){
        string now = toString(i);
        if(M == 0){
            cout << i << endl;
            return 0;
        }
        rep(j,M){
            int d = p[j].first;
            if(now[d] != p[j].second) break;
            if(j == M-1){
                cout << now << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}
