#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;cin>>s;
    int q;cin>>q;

    bool dir=true;
    str sf,sb;

    for(int i=0;i<q;i++)
    {
        int t;cin>>t;
        if(t==1)dir=!dir;
        else 
        {
            int f;
            char c;
            cin>>f>>c;
            if(dir^(f==2))sf.push_back(c);
            else sb.push_back(c);
        }
    }

    if(dir)
    {
        for(int i=sf.size()-1;i>=0;i--)cout<<sf[i];
        for(int i=0;i<s.size();i++)cout<<s[i];
        for(int i=0;i<sb.size();i++)cout<<sb[i];
    }
    else
    {
        for(int i=sb.size()-1;i>=0;i--)cout<<sb[i];
        for(int i=s.size()-1;i>=0;i--)cout<<s[i];
        for(int i=0;i<sf.size();i++)cout<<sf[i];
    }
    cout<<"\n";

    return 0;
}
