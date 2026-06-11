#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int n, m, q;
vector<int> a, b, c, d;

ll calc_score(vector<int> &x){
    ll res = 0;
    for(int i=0; i<q; i++){
        if(x[b[i]] - x[a[i]] == c[i]) res += d[i];
    }
    return res;
}

ll dfs(vector<int> &A){
    if(A.size() == n){
        return calc_score(A);
    }

    ll res = 0;
    int last = (A.empty() ? 0 : A.back());
    for(int i=last; i<m; i++){
        A.push_back(i);
        res = max(res, dfs(A));
        A.pop_back();
    }
    return res;
}

int main(void){
    
    cin >> n >> m >> q;
    a.resize(q); b.resize(q); c.resize(q); d.resize(q);
    for(int i=0; i<q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--; b[i]--;
    }

    vector<int> zzz;
    cout << dfs(zzz) << endl;
    return 0;
}