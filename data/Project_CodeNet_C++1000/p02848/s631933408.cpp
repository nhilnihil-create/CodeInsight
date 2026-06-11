#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,p;
    char ch=' ';
    string s;
    cin>>n;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        int x=s[i];
        x=x-64;
        p=(x+n)%26;
        if(p==0)p=26;
        p=p+64;
        ch=p;
        cout<<ch;
    }


}
