#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    long long int i,n;
    n=s.length();
    for(i=0;i<n;i++)
    {
        if(s[i]=='?')
        {
            if(s[i-1]=='P'&&((i-1)>=0))
                s[i]='D';
            else if(((s[i+1]=='D')||(s[i+1]=='?'))&&(i+1<n))
                s[i]='P';
            else
            s[i]='D';
        }
    }
    cout<<s;




return 0;
}