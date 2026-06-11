#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int f=0;
    for(int i=0;i<s.size();i++)
        if(s[i]=='7')f=1;
    if(f)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}