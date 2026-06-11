#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,k,i,a[200005],total=0,j;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<long long>());
    for(j=k+1;j<=n;j++)
    {
        total+=a[j];
    }
    cout<<total<<endl;
    return 0;    
}