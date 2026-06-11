#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='R') sum++;
        else if(s[i]=='S' && s[i+1]=='R') sum=0;
    }
    cout<<sum<<endl;
    return 0;
}
