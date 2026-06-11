#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i=0;
    int c,ans=0;
    while (i<3)
    {
        if (s[i]=='R')
        {
            c=0;
            while (s[i]=='R')
            {
                i++;
                c++;
            }
        }
        else
        i++;
        
        ans=max(ans,c);
    }
    cout<<ans;
}