#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,r=-1;
    string s;
    map<string,int>m;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>s;
        m[s]++;
    }
    for(auto & it:m)
        r=max(r,it.second);
    for(auto & it: m)
    {
        if(it.second==r)
            cout<<it.first<<endl;
    }
}
