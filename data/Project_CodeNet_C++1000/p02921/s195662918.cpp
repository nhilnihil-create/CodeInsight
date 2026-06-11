#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    int ans=0;
    cin>>s1>>s2;
    for(int i=0;i<3;i++)
        if(s1[i]==s2[i])
            ++ans;
        cout<<ans;
    return 0;
}

