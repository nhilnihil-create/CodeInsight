#include <bits/stdc++.h>
using namespace std;
void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}
int main()
{   init();
    string s,t;
    int ans=0;
    cin>>s>>t;
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i])ans++;
    }
    cout<<ans;
}
