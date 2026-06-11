#include<bits/stdc++.h>
using namespace std;
#define first ff
#define second ss
#define ll long long int
int main()
{
    int n;
    cin>>n;
    ll a[n+5],b[n+5];
    for(int i=1; i<n; i++)
        cin>>b[i];
    ll sum=b[1]+b[n-1];
    for(int i=1;i<n-1;i++){
      sum+=min(b[i],b[i+1]);
    }
    cout<<sum<<endl;

}
