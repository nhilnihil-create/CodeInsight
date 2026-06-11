#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    int sum=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            sum+=a[i]*a[j];
        }
    }
    cout<<sum;
    return 0;
}