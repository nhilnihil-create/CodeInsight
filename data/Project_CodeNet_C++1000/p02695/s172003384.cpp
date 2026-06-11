#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define F first
#define S second

int n, m, q, a[55], b[55], c[55], d[55], ans;
vector<int> A;

void rec(int loc){
    int s = A.size();
    if(s == n){
        int score = 0;
        for(int i = 0; i < q; ++i){
            if(A[b[i]] - A[a[i]] == c[i]){
                score += d[i];
            }
        }
        ans = max(ans, score);
    }
    else{
        for(int i = loc; i < m; ++i){
            A.push_back(i);
            rec(i);
            A.pop_back();
        }
    }
}

void solve(){
    cin >> n >> m >> q;
    for(int i = 0; i < q; ++i){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i], --b[i];
    }

    rec(0);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}