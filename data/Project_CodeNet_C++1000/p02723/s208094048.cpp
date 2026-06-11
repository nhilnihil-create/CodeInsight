#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l=s.length();
    if(l==6)
    {
        if(s[2]==s[3] && s[4]==s[5])
        {
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
    else cout<<"No\n";

}
