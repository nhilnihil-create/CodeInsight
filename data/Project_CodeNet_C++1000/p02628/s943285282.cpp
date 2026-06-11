#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int main()     //main method
{
    FIO;

       ll n,k;
       cin>>n>>k;
       ll arr[n+1];
       for(ll i=0;i<n;i++){
           cin>>arr[i];
       }
       sort(arr,arr+n);
      ll sum=0;

      for(ll i=0;i<n;i++){
          if(k>0){
              sum+=arr[i];
              k--;
          }
      }
      cout<<sum<<"\n";










    return 0;
}