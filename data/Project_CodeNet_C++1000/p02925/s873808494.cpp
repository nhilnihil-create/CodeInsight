#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    int N;
    cin >> N;
    int A[N][N-1];
    rep(i,N) rep(j,N-1) {
        cin >> A[i][j];
        A[i][j]--;
    }

    vector<int> count(N, 0);

    int leftCount = N * (N - 1) / 2;
    int days = 0;

    queue<int> que;
    rep(i,N) que.push(i);

    while (leftCount > 0) {
        vector<bool> played(N, false);
        queue<int> que_today;
        while (!que.empty()) {
            int i = que.front(); que.pop();
            if (played[i] || count[i] >= N - 1) continue;
            int k = A[i][count[i]];
            if (!played[k] && A[k][count[k]] == i) {
                count[i]++;
                count[k]++;
                played[i] = true;
                played[k] = true;
                que_today.push(i);
                que_today.push(k);
                leftCount--;
            }
        }
        if (que_today.empty()) {
            cout << -1 << endl;
            return 0;
        }
        while (!que_today.empty()) {
            que.push(que_today.front());
            que_today.pop();
        }
        days++;
    }

    cout << days << endl;
    
    return 0;
}