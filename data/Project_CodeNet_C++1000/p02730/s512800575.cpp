#include<bits/stdc++.h>
using namespace std;
bool pal(string s)
{
    string r;
    r=s;
    reverse(s.begin(),s.end());
    return s==r;
}
int main()
{
    string s,a,d;
    int i,n;
    cin>>s;
    n=s.size();
    if(pal(s))
    {
        a=s.substr(0,(n-1)/2);
        d=s.substr(((n+3)/2)-1,n-((n+3)/2)+1);
        if(pal(a)&&pal(d))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    else
        cout<<"No"<<endl;
}
