#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,k,s;
    cin >> n >> k >> s;
    vector<int> ans(n,0);
    int t=n-k+1;
    if(k==0){
        rep(i,n){
            if(ans[i]==0 && s!=1000000000) ans[i]=s+1;
            else if(ans[i]==0 && s==1000000000) ans[i]=1;
        }
        rep(i,n) cout << ans[i] << "\n";
        return 0;
    }
    int x=s/t;
    int y=s-x*t;
    if(x==0){
        rep(i,k+s-1) ++ans[i];
        rep(i,n){
            if(ans[i]==0 && s!=1000000000) ans[i]=s+1;
            else if(ans[i]==0 && s==1000000000) ans[i]=1;
        }
    }else{
        rep(i,n){
            ans[i]+=x;
            if(i%t==0) ans[i]+=y;
        }
    }
    rep(i,n) cout << ans[i] << "\n";
    return 0;
}   