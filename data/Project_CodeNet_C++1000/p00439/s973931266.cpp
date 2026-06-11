#include<iostream>
using namespace std;

int main(){
int n,k,s,ans;
int a[100001];
while(cin>>n>>k){
if(n==0&&k==0)break;
for(int i=0;i<n;i++)cin>>a[i];
s=0;
for(int i=0;i<n-k+1;i++){
if(i==0)for(int j=i;j<i+k;j++)s+=a[j];
if(i!=0){s-=a[i-1]; s+=a[i+k-1];}
if(i==0)ans=s;
if(s>ans)ans=s;}
cout<<ans<<endl;}}