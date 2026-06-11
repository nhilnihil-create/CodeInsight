#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    string s;
    cin>>s;
    int li=s.size(),r=0,l=0,R=0,L=0;
    for(int i=0; i<li; i++)
    {
        if(s[i]=='R')
            r++;
        else if(s[i]=='L')
            l++;
    }
    for(int i=0; i<li; i++)
    {
        if(i%2==0&&s[i]=='R')
            R++;
        else if(i%2!=0&&s[i]=='L')
            L++;
    }
    if(R==r&&L==l)
        cout<<"Yes";
    else
        cout<<"No";
    nl;
    return 0;
}
