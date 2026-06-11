#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s,t;
    long long ans=0;
    cin>>s;
    cin>>t;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=t[i])
            ans+=1;
    }
    cout<<ans<<endl;
}

int main()
{
    int t;
    solve();
}