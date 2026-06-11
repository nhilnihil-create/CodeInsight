#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,m;
    string s;
    cin>>n>>m>>s;
    reverse(s.begin(),s.end());
    vector<int>ans;
    int i=0;
    while(i!=n){
        bool ok=false;
        for(int j=i+m; j>i; --j){
            if(j>n)continue;
            if(s[j]=='0'){
                ok=true;
                ans.push_back(j-i);
                i=j;
                break;
            }
        }
        if(!ok){cout<<-1<<endl; return 0;}
    }
    reverse(ans.begin(),ans.end());
    rep(i,ans.size())cout<<ans[i]<<" ";
}