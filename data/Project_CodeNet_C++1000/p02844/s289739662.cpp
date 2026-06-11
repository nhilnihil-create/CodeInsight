#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int n;string  s;
    cin>>n>>s;
    int ok=0;
    ll ans =0;
    for(int i=0;i<10;i++) for(int j=0;j<10;j++) for(int k=0;k<10;k++)
    {
        for(int u=0;u<s.size();u++)
        {
            if(s[u]==char(i+'0')&&ok==0) ok++;
            else if(s[u]==char(j+'0')&&ok==1) ok++;
            else if(s[u]==char(k+'0')&&ok==2) ok++;
        }
        if(ok==3) ans++;
        ok=0;
    }
    cout<<ans<<endl;
}
