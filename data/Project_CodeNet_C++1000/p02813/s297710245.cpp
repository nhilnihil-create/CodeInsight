#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0;
    string s1="",s2="",t;
    cin>>n;
    for(int i=0;i<n;i++)
        {
            cin>>t;
            s1+=t;
        }
    for(int i=0;i<n;i++)
        {
            cin>>t;
            s2+=t;
        }
    if(s1<s2)
        swap(s1,s2);
    while(s2!=s1)
    {
        ++ans;
        next_permutation(s2.begin(),s2.end());
    }
    cout<<ans;
}

