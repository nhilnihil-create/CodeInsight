#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
const int MOD = 1000000007;

int main(){
    int n,k; cin>>n>>k;
    string s;cin>>s;
    
    int m = 0;
    
    for(int i=0; i<n; i++){
        if(!i)m++;
        else{
            if(s[i]!=s[i-1])m++;
        }
    }
    
    cout << min(n-m+2*k, n-1) << endl;
    return 0;
}