#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N, T;
int A[3010], B[3010];
vector<pii> food;
int dp[3010][3010];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> T;
    for(int i = 0; i < N; ++i){
        int A, B;
        cin >> A >> B;
        food.push_back({A, B});
    }
    sort(food.begin(), food.end());
    for(int i = 0; i < N; ++i){
        int A = food[i].first, B = food[i].second;
        for(int j = 0; j <= T; ++j){
            chmax(dp[i + 1][j], dp[i][j]);
            if(j + A < T) chmax(dp[i + 1][j + A], dp[i][j] + B);
            else if(j != T) chmax(dp[i + 1][T], dp[i][j] + B);
        }
    }
    int ans = 0;
    for(int i = 0; i <= T; ++i){
        chmax(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}