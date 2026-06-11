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
    int p,q,r;
    cin >>p>>q>>r;
    
    cout << min( p+q, min(q+r, r+p)) << endl;
    
    return 0;
}

