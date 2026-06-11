#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    string s,sta;
    int n,f=0;
    cin>>s>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x==1)f==0?f=1:f=0;
        else if(x==2)
        {
            int y;
            string o;
            cin>>y>>o;
            if(y==1)
            {
                if(!f)o+=s,s=o;
                else reverse(o.begin(),o.end()),s+=o;
            }
            else if(y==2)
            {
                if(!f)s+=o;
                else reverse(o.begin(),o.end()),o+=s,s=o;
            }
        }
    }
    if(!f)cout<<s;
    else for(int i=s.size()-1;i>=0;i--)cout<<s[i];
}
