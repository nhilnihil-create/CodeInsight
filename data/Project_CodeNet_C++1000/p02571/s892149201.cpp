#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int ans=INT_MAX;
    for(int i=0;i<s.size();i++)
    {
        int c=0;
        for(int j=0;j<t.size();j++)
        {
            if(i+j>=s.size())
            {
                c=INT_MAX;
                break;
            }
            if((i+j)<s.size()&&s[i+j]!=t[j])
                c++;
        }
        ans=min(ans,c);
    }
    cout<<ans<<endl;
}