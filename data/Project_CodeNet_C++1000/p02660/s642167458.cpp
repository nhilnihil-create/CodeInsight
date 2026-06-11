#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main()
{
    map<int,int> m;
    long long int n;
    cin>>n;
    for(int i=2;i<=sqrt(n);i++)
    {
        while(n%i==0)
        {
            m[i]++;
            n=n/i;
        }
    }
    if(n>1)
    m[n]++;
    int ans=0;
    for(auto it:m)
    {
        int p=it.second;
        int curr=1;
        while(p>=curr)
        {
            ans++;
            p-=curr;
            curr++;
        }
    }
    cout<<ans<<endl;

}