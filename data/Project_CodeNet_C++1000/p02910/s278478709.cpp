#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string s,p;
int main()
{
    ft
    int t,i,j,n,m,l,r;
    cin>>s;
    l=0;
    r=s.size();
    for(i=0;i<r;i++)
    {
        if(i%2==0)
        {
            if(!(s[i]=='R' || s[i]=='U' || s[i]=='D'))
            {
                l=1;
            }
        }
        else
        {
            if(!(s[i]=='L' || s[i]=='U' || s[i]=='D'))
            {
                l=1;
            }
        }
    }
    (l==1)? cout<<"No\n": cout<<"Yes\n";
    return 0;
}