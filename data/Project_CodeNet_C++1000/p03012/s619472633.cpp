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
    int n;
    cin >> n;
    v sum(n);
    int w;
    rep(i,n){
        cin >> w;
        if(i)sum[i] += sum[i-1];
        sum[i] += w;
    }
    int ans = sum[n-1];
    
    rep(i,n){
        ans = min(ans, abs(sum[n-1] - sum[i]*2));
    }
    cout << ans << endl;
    return 0;
}