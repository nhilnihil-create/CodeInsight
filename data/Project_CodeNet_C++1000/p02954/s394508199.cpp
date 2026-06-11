#include<bits/stdc++.h>
#define INFTY 10000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};
const int INF = 1e9;
const int A = 1000005;
int main(){
    string s;cin>>s;
    int n;n = s.length();
    vector<int> st={},g={},ans(n,0);
    rep(i,n-1){
        if(s[i]=='R'&&s[i+1]=='L')st.emplace_back(i);
        if(s[i]=='L'&&s[i+1]=='R'){g.emplace_back(i);}
    }
    int l = 0;
    g.emplace_back(n-1);
    rep(i,st.size()){
        
        int x = st[i];
        int r = g[i];
        ans[x] = 1 + (x-l)/2 + (r-x)/2;
        ans[x+1] = r + 1 - ans[x] - l;
        l = r + 1;
       // cout<<l<<r<<x<<endl;
    }
    rep(i,n){
        printf("%d ",ans[i]);
    }
    return 0;
}