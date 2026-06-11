#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
int main()
{
    int n,i,j,k;
    cin>>n;
    int a[n],b[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
        k=0;
    for(i=0;i<n;i++)
    {
        if(k==3) break;
    if(a[i]==b[i]) k++;
    else k=0;
    }
    if(k==3) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
