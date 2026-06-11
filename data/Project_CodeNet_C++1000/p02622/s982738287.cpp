#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int ans=0;
    int len=(int)s1.length();
    for(int i=0;i<len;i++){
        if(s1[i]!=s2[i])
            ans++;
    }
    cout<<ans<<"\n";
    return 0;
}