#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define Sort(Array) sort(Array.begin(), Array.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define out(ans) cout << ans << endl;
const int MOD = 1000000007;
const int INF = 2147483647;
const ld PI = 3.14159265358979323846;

//------------↓------------- M -------------- E ---------------- M --------------- O ---------------↓--------------//
// コンパイル 
// g++ -std=c++1z
//
// -------型変換--------
// int を string に変換
// string s = to_string(n);
// string を int に変換
// int n = stoi(s);
//
// -------二分探索---------
// k以上の値が最初に現れる時のイテレータ
// lower_bound(data.begin(), data.end(), k)
// kより大きい値が最初の現れる時のイテレータ O(logN)
// upper_bound(data.begin(), data.end(), k)
// kがdataに存在するかをtrue or falseで返す O(logN)
// binary_search(data.begin(), data.end(), k)
// 
//
//
//
//
//
// 
//------------↑------------- M -------------- E ---------------- M --------------- O ---------------↑--------------//





int main() {

    int N, M; cin >> N >> M;
    vector<vector<int>> friends(N+1);
    rep(i,M) {
        int a, b; cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    
    bool seen[N+1];
    rep(i,N+1) seen[i] = false;
    int ans = 0;
    for (int i = 1; i < N+1; ++i) {
        if (seen[i]) continue;

        int tmp_ans = 1;
        seen[i] = true;
        queue<int> q;
        q.push(i);
        while (!empty(q)) {
            int now = q.front();
            q.pop();
            rep(j,friends[now].size()) {
                if (seen[friends[now][j]]) continue;

                seen[friends[now][j]] = true;
                q.push(friends[now][j]);
                ++tmp_ans;
            }
        }

        ans = max(ans, tmp_ans);
    }

    cout << ans << endl;


    return 0;
}



