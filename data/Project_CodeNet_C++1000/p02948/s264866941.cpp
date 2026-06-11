#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i=0; i< (int)(n); i++)
typedef long long ll;


int main() {
    int N, M, ai, bi;
    vector<pair<int,int>> ab;
    cin >> N >> M;
    // vector<vector<int>> dp(N+1);
    map<int, vector<int>> day2weight;
    rep(i, N){
        cin >> ai >> bi;
        day2weight[ai].push_back(bi);
    }

    priority_queue<int> tasks;
    int ans = 0;
    for(int i=1; i < M+1; i++) {
        vector<int> weights = day2weight[i];
        rep (j, weights.size()) {
            tasks.push(weights[j]);
        }
        if (!tasks.empty()) {
            ans += tasks.top();
            tasks.pop();
        }
    }
    cout << ans;
}