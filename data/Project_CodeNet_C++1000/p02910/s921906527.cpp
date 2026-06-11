#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    string s;
    cin>>s;
    bool ans=true;
    rep(i,s.size()){
        if(i%2==0 && s[i]=='L') ans=false;
        if(i%2==1 && s[i]=='R') ans=false;
    }
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}