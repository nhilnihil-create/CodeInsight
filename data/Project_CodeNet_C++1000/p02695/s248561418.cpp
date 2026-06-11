#include <iostream>
#include <algorithm>
#include <vector> //動的配列
#include <string>
#include <list> //双方向リスト
#include <map> //連想配列
#include <set> //集合
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <numeric>
#include <tuple>



typedef long long ll;


using namespace std;

typedef pair<int, int> P;
#define FOR(i,a,b) for(int i=(int)(a) ; i < (int) (b) ; ++i )
#define rep(i,n) FOR(i,0,n)
#define sz(x) int(x.size())

int n, m, q;
vector<vector<int>> v; 

void dfs (vector<int> a, int* ans) {
    if (a.size() == n+1){
        int score = 0;
        rep(i,q){
            if (a[v[i][1]] - a[v[i][0]] == v[i][2]) score += v[i][3];
        }
        *ans = max(*ans, score);
        return ;
    }

    a.push_back(*a.rbegin());
    while (*a.rbegin() <= m) {
        dfs(a, ans);
        (*a.rbegin())++;
    }

}



int main(){
    cin >> n>> m >> q;
    v.resize(q, vector<int> (4,0));
    rep (i,q) {
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
    }
    vector<int> comb(1,1);

    int ans = 0;
    dfs(comb, &ans);

    cout << ans;
    return 0;
}