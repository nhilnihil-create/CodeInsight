#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)

int main(void){
    map<int,int> seen;
    int n;
    cin>>n;
    bool ok=true;
    rep(i,n){
        int a;
        cin>>a;
        a--;
        seen[a]++;
        if(seen[a]!=1) ok=false;
    }
    if(ok) puts("YES");
    else puts("NO");
    return 0;
}