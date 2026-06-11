#include<bits/stdc++.h>
using namespace std;
#define int long long int 
int32_t main()
{
    string str;
    cin>>str;
    map<int,int> m;
    m[0]=1;
    int temp=0,x=1,ans=0;
    for(int i=str.size()-1;i>=0;i--)
    {
        temp=(temp+x*(str[i]-'0'))%2019;
        ans+=m[temp];
        m[temp]++;
        x=(x*10)%2019;
    }
    cout<<ans<<endl;
}