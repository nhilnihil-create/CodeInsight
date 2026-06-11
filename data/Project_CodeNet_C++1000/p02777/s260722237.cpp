#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)

int main(void){
    string s,t,u;
    int a,b;
    cin>>s>>t>>a>>b>>u;
    if(s==u) a--;
    else b--;
    cout<<a<<" "<<b<<endl;
    return 0;
}