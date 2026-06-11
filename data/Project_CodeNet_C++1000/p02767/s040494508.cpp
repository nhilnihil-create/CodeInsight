#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n+1];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    sort(ar,ar+n);
    int mn=1e9;
    for(int i=ar[0];i<=ar[n-1];i++)
    {
        int cal=0;
        for(int j=0;j<n;j++)
            cal+=pow(ar[j]-i,2);
        mn=min(mn,cal);
    }
    cout<<mn<<endl;
    return 0;
}
