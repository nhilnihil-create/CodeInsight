#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<string> ans;
int n;
void dfs(string s){
    if(s.size()==n){
        ans.push_back(s);
        return;
    }

    char ma='a';
    rep(i,s.size()){
        ma=max(ma,s[i]);
    }
    
    if(ma=='z'){
        for(char x='a';x<='z';x++){
            dfs(s+x);
        }
    }
    else{
        for(char x='a';x<=char(ma+1);x++){
            dfs(s+x);
        }
    }
    
}

int main() {
    
    cin>>n;

    dfs("a");

    sort(all(ans));
    rep(i,ans.size()) cout<<ans[i]<<endl;
}