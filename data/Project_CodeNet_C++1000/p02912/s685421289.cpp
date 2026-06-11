#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    long long n,m,i,k,s;
    cin>>n>>m;
    long long a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    multiset<long long>l;
    for(i=0;i<n;i++)
    {
        l.insert(a[i]);
    }
    while(m--)
    {
        k=*l.rbegin();
        l.erase(--l.end());
        l.insert(k/2);
    }
    s=0;
    for(auto i:l)
    {
        s+=i;
    }
    cout<<s<<"\n";
    return 0;
}