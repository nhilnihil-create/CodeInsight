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
    int n,l;cin >>n>>l;
    
    int before = l*n + n*(n-1)/2;
    int bite;
    
    if(l<=0 && l+n-1>=0)bite = 0;
    else if(l>0)bite = l;
    else bite = l+n-1;
    
    cout << before - bite << endl;
    
    return 0;
}
