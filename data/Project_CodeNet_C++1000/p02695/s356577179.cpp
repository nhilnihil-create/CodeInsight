#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;
typedef pair<int, int> PII;

vector<int> a, b, c, d;
int n, m, q;
int ans = 0;

void dfs(vector<int> A){
    if(A.size() == n){
        int now = 0;
        rep(i, q){
            if(A[b[i]] - A[a[i]] == c[i]) now += d[i];
        }
        ans = max(ans, now);
        return;
    }
    A.push_back(A.back());
    while(A.back() <= m){
        dfs(A);
        A.back()++;
    }
}

int main(){
    cin >> n >> m >> q;
    a = b = c = d = vector<int>(q);
    rep(i, q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }

    dfs(vector<int>(1, 1));

    cout << ans << endl;
}