#include <bits/stdc++.h>

using namespace std;

int main()
{   int count=0,maxm=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='R') count++;
        else count=0;
        maxm=max(maxm,count);
    }
    cout<<maxm;
    return 0;
}
