#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

int n, m, q; 
vector<ll> a, b, c, d;

ll score(const vector<int> &A){
    ll res = 0;
    for(int i=0; i<q; ++i){
        if(A[b[i]]-A[a[i]]==c[i]){res += d[i];}
    }
    return res;
}

ll dfs(vector<int> &A){
    if(A.size()==n){return score(A);}
    int v; ll res = 0; 
    if(!A.empty()){v = A.back();}else{v = 1;}
    for(int nv=v; nv<=m; ++nv){
        A.push_back(nv);
        res = max(res, dfs(A));
        A.pop_back();
    }
    return res;
}

int main(){
    cin >> n >> m >> q;
    a.resize(q); b.resize(q); c.resize(q); d.resize(q);
    for(int i=0; i<q; ++i){
        cin >> a[i] >> b[i] >> c[i] >> d[i]; a[i]--; b[i]--;
    }
    vector<int> X;
    cout << dfs(X) << endl;
    return 0;
}