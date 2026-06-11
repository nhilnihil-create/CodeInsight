#include<bits/stdc++.h>
#define ll long long int
#define pi 3.14159265358979323846
#define mod 1000000007
using namespace std;
int main()
{
    ll n,k,sum1=0,sum2=0,diff1=0,diff2=0,diff3=0,s21=0,s22=0,cnt=0;
    cin>>n>>k;
    n=n+1;
    for(int i=k;i<=n;i++)
    {
        diff1=i-1;
        sum1=diff1*(diff1+1)/2;
        diff2=n-1;
        s21=diff2*(diff2+1)/2;
        diff3=n-i-1;
        s22=diff3*(diff3+1)/2;
        sum2=s21-s22;
       // cout<<sum1<<" "<<sum2<<endl;
        cnt+=(sum2-sum1+1);
        //cout<<"cnt "<<cnt<<endl;
    }
   // cout<<cnt<<endl;
    ll kk=cnt%mod;
    cout<<kk<<endl;
}