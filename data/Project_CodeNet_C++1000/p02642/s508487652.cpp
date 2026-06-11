#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    bool a[1000005];
    for(int i=0;i<=1000004;i++)
    {
        a[i]=true;
    }
    int in;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>in;
        m[in]++;
    }
    for(auto j:m)
    {
        if(j.second>1) 
        {
            a[j.first]=false;
        }
        in=j.first;
        for(int j=2*in;j<=1000004;j+=in)
        {
            a[j]=false;
        }
    }
    int ans=0;
    for(auto j:m)
    {
        if(a[j.first]) ans++;
    }
    cout<<ans;

}