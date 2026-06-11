#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<string>
#include<iomanip>
#include<queue>
#include<functional>
#include<cmath>
#include<map>
#include<tuple>
#include <numeric>
#define rep(i,n) for(int i=0; i<(int)n; i++)//n回繰り返す
#define rrep(i,n)for(int i=n-1;i>=0;i--)
#define REP(i,n) for (int i = 1; i <= (int)n; i++)//i=1からi=nまで
#define RREP(i,n)for(int i=n;i>=1;i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using graph = vector<vector<int>>;
const ll mod = pow(10, 9) + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const double pi = 3.14159265358979323846;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N, M; cin >> N >> M;    graph r(N + 1);
    rep(i, M) {
        int A, B; cin >> A >> B;
        
            r[A].push_back(B);
        
       
            r[B].push_back(A);
        
    }
    vector<bool>rooted(N + 1, false);
    int ans = 0;
    REP(i, N) {
        if (rooted[i] == false) {
            rooted[i] = true;
            queue<int> q;
            for (int& e : r[i]) {
                q.push(e);
            }
            while (!q.empty()) {
                int a = q.front();
                rooted[a] = true;
                q.pop();
                for (int& e : r[a]) {
                    if(rooted[e]==false)
                    q.push(e);
                }
            }
            ans++;
        }

    }

    cout << ans - 1 << endl;
}



