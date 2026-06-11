#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mod 1000000007

int main()
{
    int n;
    cin>>n;

    int a[n];
    ll d=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        d^=a[i];
    }
    for(int i=0;i<n;i++)
        cout<<(d^a[i])<<" ";
    cout<<"\n";
    return 0;
}
