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
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define INF 100000000000
#define MAX 200001
#define MOD 1000000007

int main(){
    int N, T; 
    cin >> N >> T;
    vector<P> AB(N);
    for(int i = 0; i < N; i++){
        int A, B;
        cin >> A >> B;
        AB[i] = {A, B};
    }
    int ans = 0;
    sort(AB.begin(), AB.end());
    vector<vector<int>> dp(N + 5, vector<int>(T+3, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < T; j++){
            if(j - AB[i].first >= 0) dp[i + 1][j] = max(dp[i][j - AB[i].first] + AB[i].second, dp[i][j]);
            else dp[i + 1][j] = dp[i][j];
            ans = max(ans, dp[i][j] + AB[i].second);
        }   
    }
    cout << ans << endl;
}