#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    for(unsigned int i=0;i<s.size();i++)
    {
        char x=s[i];
        cout<<string(1,'A'+(n+x-13)%26);
    }
}