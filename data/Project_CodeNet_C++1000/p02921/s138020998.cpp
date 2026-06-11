#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
     if(s[0]==t[0]&&s[1]==t[1]&&s[2]==t[2]){cout<<3<<endl;}
     else if(s[0]==t[0]&&s[1]==t[1]&&s[2]!=t[2]){cout<<2<<endl;}
     else if(s[0]==t[0]&&s[1]!=t[1]&&s[2]==t[2]){cout<<2<<endl;}
     else if(s[0]!=t[0]&&s[1]==t[1]&&s[2]==t[2]){cout<<2<<endl;}
     else if(s[0]!=t[0]&&s[1]!=t[1]&&s[2]==t[2]){cout<<1<<endl;}
     else if(s[0]!=t[0]&&s[1]==t[1]&&s[2]!=t[2]){cout<<1<<endl;}
     else if(s[0]==t[0]&&s[1]!=t[1]&&s[2]!=t[2]){cout<<1<<endl;}
     else {cout<<0<<endl;}
}
