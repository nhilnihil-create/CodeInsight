#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<int>;
using vv = vector<v>;
//const int MOD = 1000000007;
const int MOD = 998244353;
const int INF = 1001001001;

int main(){
    int n,x;cin >>n>>x;
    v l(n);
    rep(i,n)cin >> l[i];
    
    int d=0;
    int ans = 1;
    rep(i,n){
        d += l[i];
        if(d>x)break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}

