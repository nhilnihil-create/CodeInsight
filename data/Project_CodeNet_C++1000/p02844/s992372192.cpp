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
#define INF 1000000000
#define MAX 200001
#define PI 3.141592653589793

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const ll MOD = 1000000007;

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

set<string> s;
int ans = 0;

void dfs(int idx,string now, int N, string S){
    if(now.size() == 3){
        ans++;
        return;
    }
    for(int i = idx; i < N; i++){
        string new_s = now + S[i];
        if(s.find(new_s) != s.end()) continue;
        s.insert(new_s);
        dfs(i+1,new_s,N,S);
    }
}

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    dfs(0,"",N,S);
    cout << ans << endl;
}