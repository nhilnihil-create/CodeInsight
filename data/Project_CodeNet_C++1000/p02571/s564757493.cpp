#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int a=t.size();
    for(int i=0;i<=s.size()-t.size();i++)
    {
        int p=0;
        for(int j=0;j<t.size();j++)
        {
            if(t[j]!=s[i+j])
                p++;
        }
        a=min(a,p);
    }
    cout<<a<<endl;
    return 0;
}
