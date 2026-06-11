#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll t,n,f,i,tog;
    list<char> l;string s;
    cin>>s;
    for(i=0;i<s.length();i++)
        l.push_back(s[i]);
    cin>>n;
    char c;tog=0;
    while(n--)
    {
        f=0,c='\0';
        cin>>t;
        if(t==1)
        {
           tog=1-tog;
        }
        else if(t==2)
        {
            cin>>f>>c;
            if((f==1&&tog==0)||(f==2&&tog==1))
                l.push_front(c);
            else if((f==2&&tog==0)||(f==1&&tog==1))
                l.push_back(c);
        }
    }
    list<char>::iterator it;
    if(tog==1)
        l.reverse();
    for(it=l.begin();it!=l.end();it++)
        cout<<*it;
}
