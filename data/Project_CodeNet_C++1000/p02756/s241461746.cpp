// https://atcoder.jp/contests/abc158/tasks/abc158_d
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define lli int

int main()
{
    lli q,t,f,cnt=0;
    string s,st,en;
    char c;
    cin>>s;
    cin>>q;
    st="";
    en="";
    while(q--)
    {
        cin>>t;
        if(t==1)
        {
            cnt++;
        }
        else
        {
            cin>>f>>c;
            if(f==1)
            {
                if(cnt&1)
                    en=en+c;
                else
                    st=c+st;
            }
            else
            {
                if(cnt&1)
                    st=c+st;
                else
                    en=en+c;
            }
        }
    }
    s=st+s+en;
    if(cnt&1)
        reverse(s.begin(),s.end());
    cout<<s<<"\n";
    return 0;
}