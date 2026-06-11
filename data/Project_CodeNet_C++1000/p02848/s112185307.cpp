#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    string s;
    cin>>n>>s;
    for(i=0;i<s.size();i++)
    {
        if(s[i]+n>90)
            cout<<char((n-(90-s[i]))+64);
        else
            cout<<char(s[i]+n);
    }
    cout<<endl;
}
