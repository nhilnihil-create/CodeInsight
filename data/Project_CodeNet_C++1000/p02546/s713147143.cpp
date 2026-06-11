#include<bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve()
{
    string s; cin>>s;
    int n=s.length();
    if(s[n-1]=='s')s+="es";
    else s+='s';
    cout<<s;
    return ;
    
}


 
 
 signed main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    
    
    int T; 
    T=1;
    //cin>>T;
    while(T--)
    {
          solve();
    }
    
    
        return 0;
	
}