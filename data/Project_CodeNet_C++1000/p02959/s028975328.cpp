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
    for(int i=0; i<=n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
        cin>>b[i];
    ll sum=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]>b[i]){sum+=b[i];b[i]=0;}
        else {sum+=a[i];b[i]-=a[i];}
        if(b[i])
        {
            if(a[i+1]>b[i]){sum+=b[i];a[i+1]-=b[i];}
        else {sum+=a[i+1];a[i+1]=0;}
        }
        //cout<<"Sum = "<<sum<<endl;
    }
    cout<<sum<<endl;

}
