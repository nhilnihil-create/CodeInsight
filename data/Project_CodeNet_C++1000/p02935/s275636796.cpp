#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double a[n];
    for(int i=0;i<n;i++)
       cin>>a[i];
    sort(a,a+n);
    double sum=0;
    for(int i=1; i<n; i++)
        a[i]=(a[i]+a[i-1])/2;;
    cout<<a[n-1]<<endl;

}
