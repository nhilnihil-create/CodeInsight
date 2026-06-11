#include<bits/stdc++.h>
using namespace std;
int flag[1001];
map<int,int>mp;
map<int,int>mp1;

int main()
{
    string s,s1;
    int c=0,f=0,i;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        c=i+1;
        if(c%2!=0)
        {
            if(s[i]=='R'||s[i]=='U'||s[i]=='D')
             continue;
            else
                f=1;

        }
       else  if(c%2==0)
        {
            if(s[i]=='L'||s[i]=='U'||s[i]=='D')
                continue;
            else
                f=1;

        }
    }
    if(f==1)
        cout<<"No"<<"\n";
    else
        cout<<"Yes"<<"\n";
}
