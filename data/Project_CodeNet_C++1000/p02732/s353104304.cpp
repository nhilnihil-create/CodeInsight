#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    long long int sum=0;
    for(auto i:m)
    {
        long long int x=i.second;
        sum=sum+(x*(x-1))/2;
    }
    for(int i=0;i<n;i++)
    {
        cout<<sum-m[a[i]]+1<<"\n";
    }
 
}