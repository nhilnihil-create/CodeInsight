#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=2e5+9;
const int mod=1e9+7;
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    int ans=0;
    cin>>s;
    cin>>t;
    for(int i=0;i<s.size();i++){
    	if(s[i]!=t[i])ans++;
    }
    cout<<ans;

    
}



