#include<bits/stdc++.h>
#include<string.h>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int a[n+5],b[n+5];
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(long long int i=0;i<n;i++)
    {
        b[a[i]]=i+1;
    }
    for(long long int i=1;i<=n;i++) cout<<b[i]<<" ";
    return 0;
}
