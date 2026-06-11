#include <bits/stdc++.h>
using namespace std;
#define lli long long

int main() 
{
    string s;
    cin >> s;
    
    int ans = (s[0]=='R')?1:0;
    
    if(s[1]=='R') ans++;
    
    if(s[2]=='R' && s[2]==s[1]) ++ans;
    else if(s[2]=='R' && s[2]!=s[1]) ans=1;
    
    cout<<ans<<endl;
    return 0;
}