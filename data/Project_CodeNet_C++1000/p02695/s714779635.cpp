#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl "\n"
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int N, M, Q, ans;
vector<vector<int>> q(51, vector<int>(4));

void dfs(vector<int> A){
    if(A.size() == N+1) {
        int s = 0;
        rep(i, 0, Q){
            int a = q[i][0], b = q[i][1], c = q[i][2], d = q[i][3];
            if(A[b]-A[a] == c) s += d;
        }
        chmax(ans, s);
        return;
    }

    A.push_back(A.back());
    while(A.back() <= M){
        dfs(A);
        A.back()++;
    }
}

int main() {
    cin >> N >> M >> Q;
    rep(i, 0, Q) rep(j, 0, 4){
        cin >> q[i][j];
    }
    dfs(vector<int>(1, 1));
    cout << ans << endl;
    return 0;
}
