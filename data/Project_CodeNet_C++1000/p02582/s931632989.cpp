
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;int ans=INT_MIN,c=0;
    cin>>s;
    for(int i=0;i<3;i++)
    {
        if(s[i]=='R' )
        {
            c++;
        }
        else{
            c=0;
        }
        ans=max(c,ans);
    }
    cout<<ans;
    return 0;
}
