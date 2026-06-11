#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int n,m,q;
vector<int>a,b,c,d;
int dfs(int index,vector<int>& A) {
    if(index==n) {
        int res = 0;
        rep(i,q) {
            if(A[b[i]] - A[a[i]] == c[i]) res += d[i];
        }
        return res;
    }
    int res = 0;
    for(int i = 1;i<=m;i++) {
        if(index>0 && i<A[index-1]) continue;
        A.push_back(i);
        int tmp = dfs(index+1,A);
        A.pop_back();
        res = max(res,tmp);
    }
    return res;
}

int main() {
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    rep(i,q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;b[i]--;
    }
    vector<int>A;
    int ans = dfs(0,A);
    cout << ans << endl;
}