#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
ll n;
cin>>n;
ll arr[n];
for(int i=0; i<n;i++)
cin>>arr[i];
sort(arr, arr+n);
ll ans=0;
for(int i=0; i<n;i++)
for(int j=i+1; j<n;j++)
for(int k=j+1; k<n;k++)
     if(arr[i]!=arr[j] && arr[j] != arr[k] && arr[k] < arr[i] + arr[j]){
    //cout<<arr[i]<<' '<<arr[j]<<' '<<arr[k]<<endl;;
    ans++;
    }
         
cout<<ans;
}