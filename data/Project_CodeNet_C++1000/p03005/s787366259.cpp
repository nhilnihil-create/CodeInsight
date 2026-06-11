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
    int n,k;cin >>n>>k;
    
    if(k==1){
        cout << 0 << endl;
        return 0;
    }
    
    cout << n-k << endl;
    
    return 0;
}