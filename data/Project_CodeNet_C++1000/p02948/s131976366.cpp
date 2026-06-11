#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int ans = 0;
    priority_queue<int> que;
    vector<int> v[100010];
    rep(i, N) {
        int A, B;
        cin >> A >> B;
        v[A].push_back(B);
    }
    rep(i, M) {
        for(auto& e: v[i + 1]) {
            que.push(e);
        }
        if(que.size()) {
            ans += que.top(); que.pop();
        }
    }
    cout << ans << endl;

    return 0;
}
