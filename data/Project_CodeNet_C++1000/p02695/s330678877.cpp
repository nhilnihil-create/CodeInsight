#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef float fl;
typedef long long ll;

vector<int> A;
int n, m, q; 
int a[50], b[50], c[50], d[50];
ll ans;

ll score(vector<int> &A) {
    ll ans = 0;
    rep(i,q) if(A[b[i]] - A[a[i]] == c[i]) ans += d[i];
    return ans;
}

ll dfs(vector<int> &A) {
    if(A.size() == n) return score(A);

    int prev_last = (A.empty()? 1 : A.back());
    for(int add = prev_last; add <= m; ++add) {
        A.push_back(add); 
        ans = max(ans, dfs(A));
        A.pop_back();
    }

    return ans;
}

int main(){
    cin >> n >> m >> q;
    rep(i,q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i], --b[i];
    }
    cout << dfs(A) << endl;
    return 0;
}