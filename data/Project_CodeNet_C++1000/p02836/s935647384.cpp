#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int ans=0;
    string s;
    cin>>s;
    string t=s;
    reverse(t.begin(),t.end());
    for(unsigned int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=t[i]) ans++;
    }
    cout<<ans;
}