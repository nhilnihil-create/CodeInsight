#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];
string s[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i]>>a[i];
    string k;
    cin>>k;
    bool flag=false;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(flag) ans+=a[i];
        if(s[i]==k) flag=true;
    }
    cout<<ans;
}
