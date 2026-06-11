#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<int> A(a),B(b),C(c);
    rep(i,a) cin >> A[i];
    rep(i,b) cin >> B[i];
    rep(i,c) cin >> C[i];

    sort(A.rbegin(),A.rend());
    sort(B.rbegin(),B.rend());
    sort(C.rbegin(),C.rend());

    multiset<int> m;
    rep(i,x) m.insert(A[i]);
    rep(i,y) m.insert(B[i]);

    rep(i,c){
        if(*m.begin()<C[i]){
            m.erase(m.begin());
            m.insert(C[i]);
        }else break;
    }
    ll ans = 0;
    for(auto it=m.begin();it!=m.end();it++){
        ans += *it;
    }

    cout << ans << endl;





 }