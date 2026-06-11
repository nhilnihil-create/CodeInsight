#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl

int main() {
    int N, M;
    cin >> N >> M;
    int A[N], B[N];
    priority_queue<int>Q[100001];
    priority_queue<int>Q_ALL;
    Q_ALL.push(0);
    rep(i, N) cin >> A[i] >> B[i], --A[i], Q[A[i]].push(B[i]);
    int ans = 0;
    for(int i = 0; i < M; ++i) {
        int q2 = Q_ALL.top();
        if(!Q[i].empty()) {
            int q1 = Q[i].top();
            if(q1 > q2) {
                ans += q1;
                Q[i].pop();
            }else {
                ans += q2;
                Q_ALL.pop();
            }
            while(!Q[i].empty()) {
                Q_ALL.push(Q[i].top());
                Q[i].pop();
            }
        }else {
            ans += q2;
            Q_ALL.pop();
            Q_ALL.push(0);
        }
    }
    cout << ans << endl;
}
