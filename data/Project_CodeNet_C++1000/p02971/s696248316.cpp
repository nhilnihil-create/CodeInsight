#include<bits/stdc++.h>
using namespace std;
bool comp(pair<long long int,long long int>a,pair<long long int,long long int>b)
{
    if(a.first==b.first)
    {
        if(a.second<=b.second)
        return true;
        else
        return false;
    }
    if(a.first>b.first)
    return true;
    else return false;
}
long long int gcd(long long int bdda,long long int chota)
{
    if(chota==0)
        return bdda;
    return gcd(chota,bdda%chota);
}
void solve()
{
    int n;
    cin>>n;
    int a[n],b[n],j=0;
    for(auto &i:a){cin>>i,b[j]=i;j++;}
    sort(b,b+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[n-1])
        cout<<b[n-2]<<endl;
        else
        cout<<b[n-1]<<endl;
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;    
    t=1;

    //cin>>t;
    while(t--)
    {
        solve();
    }
}
