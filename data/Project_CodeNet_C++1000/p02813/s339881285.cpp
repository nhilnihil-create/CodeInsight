#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;


int main(){
    int n, a=0, b=0, cnt=0;
    cin >> n;
    vector<int> p(n), q(n), perm(n);
    rep(i, n)perm[i] = i+1;
    rep(i, n)cin >> p[i];
    rep(i, n)cin >> q[i];
    
    while(next_permutation(perm.begin(), perm.end())){
        cnt++;
        if(perm == p)a = cnt;
        if(perm == q)b = cnt;
    }
    
    int ans;
    if(a==b){
        ans = 0;
    }else{
        ans = abs(a-b);
    }
    cout << ans << endl;
    
}