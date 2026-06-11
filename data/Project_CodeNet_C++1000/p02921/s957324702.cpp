#include<bits/stdc++.h>
using namespace std;
int flag[1001];
map<int,int>mp;
map<int,int>mp1;

int main()
{
    string s,s1;
    int c=0;
    cin>>s>>s1;
    if(s[0]==s1[0])
        c++;
    if(s[1]==s1[1])
        c++;
    if(s[2]==s1[2])
        c++;

    cout<<c<<"\n";

}
