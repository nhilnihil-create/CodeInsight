#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
   int k,n;
   cin>>n>>k;
   vector<int> arr(n);
   int l=1,r=0;
   for(int i=0;i<n;i++){
       cin>>arr[i];
       r=max(r,arr[i]);
   }
   while(l!=r){
       int m=(l+r)/2;
       int s=0;
       for(int i=0;i<n;i++){
           s+=(arr[i]-1)/m;
       }
       if(s<=k)
        r=m;
       else
        l=m+1;
   }
   cout<<l<<endl;
}
   