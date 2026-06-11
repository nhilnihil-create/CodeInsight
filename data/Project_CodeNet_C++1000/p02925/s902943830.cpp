#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int id[1005][1005];
int toID(int x, int y){
    if(x > y)swap(x, y);
    return id[x][y];
}

vector<vector<int> > to(1000005);

int d[1000005];
bool visited[1000005];
bool calc[1000005];
int dfs(int x){
    if(visited[x]){
        if(calc[x]){
            return d[x];
        } else {
            return -1;
        }
    }
    visited[x] = true;
    d[x] = 1;
    for(int p : to[x]){
        int k = dfs(p);
        if(k == -1)return -1;
        d[x] = max(d[x], k + 1);
    }
    calc[x] = true;
    return d[x];
}


int main() {
    int N; cin >> N;
    vector<vector<int> > A(N);
    rep(i, N){
        rep(j, N-1){
            int a; cin >> a;
            a--;
            A[i].push_back(a);
        }
    }

    int X = 0;
    rep(i, N){
        rep(j, N-1){
            int x = A[i][j];
            if(x > i){
                id[i][x] = X++;
            }
        }
    }

    rep(i, N){
        rep(j, N-1){
            A[i][j] = toID(i, A[i][j]);
        }
    }

    rep(i, N){
        rep(j, N-2){
            to[A[i][j]].push_back(A[i][j+1]);
        }
    }

    int ans = 0;
    rep(i, (N*N-1)/2){
        int y = dfs(i);
        if(y == -1){
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, y);
    }

    cout << ans << endl;

    return 0;
}