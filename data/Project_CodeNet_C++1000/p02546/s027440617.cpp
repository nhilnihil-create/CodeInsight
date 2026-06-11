#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len = s.size();
    if(s[len-1]=='s'){cout<<s<<"es";}
    else{cout<<s<<"s";}
}