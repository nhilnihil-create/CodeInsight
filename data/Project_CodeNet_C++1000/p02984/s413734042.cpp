#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int a[N],res[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    long long c=0;
    for(int i=1;i<=n;i++)
    if(i%2) c+=a[i];
    else    c-=a[i];
    res[1]=c;
    for(int i=1;i<=n-1;i++)
    res[i+1]=2*a[i]-res[i];
    for(int i=1;i<=n;i++)
    cout<<res[i]<<" ";
}