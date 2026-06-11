#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define vl vector
using namespace std;
int main()
{
    ll n,a,b,i,j;
    string s;
    cin>>s>>n;
    list<char> li;
    ll count=0;
    bool rev=false;
    for(i=0;i<s.size();i++) li.pb(s[i]);
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a==1)
        {
            count++;
            rev=!rev;
        }
        else
        {
            char c;
            cin>>b>>c;
            if(rev)
            {
                if(b==1) li.pb(c);
                else li.pf(c);
            }
            else
            {
                if(b==1) li.pf(c);
                else li.pb(c);
            }
        }
    }
    if(count%2) reverse(li.begin(),li.end());
    for(auto itr=li.begin();itr!=li.end();itr++) cout<<*itr;
    
}