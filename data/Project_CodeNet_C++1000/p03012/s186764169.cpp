#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin>>n;
int arr[n],pre[n]={0},suf[n]={0},w=0,min=INT_MAX;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
w+=arr[i];
pre[i]=w;

}
w=0;
for(int i=n-1;i>=0;i--)
{
    w+=arr[i];
    suf[i]=w;
}
for(int i=0;i<n-1;i++)
{
    if(min>abs(pre[i]-suf[i+1]))
    min=abs(pre[i]-suf[i+1]);
    if(min==0)
    {
        cout<<0;
        return 0;
    }
}
cout<<min;
}
