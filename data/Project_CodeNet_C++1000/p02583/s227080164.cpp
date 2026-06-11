#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define pb push_back
#define mk make_pair
int main(){
   int n;
   cin>>n;
   vector<ll> arr(n);
   for(int i=0;i<n;i++)
    cin>>arr[i];
  int ans=0;
  for(int i=0;i<n-2;i++){
      for(int j=i+1;j<n-1;j++){
          if(arr[j]==arr[i])
           continue;
          for(int k=j+1;k<n;k++){
             if(arr[k]==arr[i] || arr[k]==arr[j])
              continue;
             if((arr[i]+arr[j]>arr[k]) && (arr[i]+arr[k]>arr[j]) && (arr[j]+arr[k]>arr[i]))
               ans++;
          }
      }
  }
  cout<<ans<<endl;
   
}
