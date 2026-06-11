#include <bits/stdc++.h>
using namespace std;

   int main() {
       
       int n;
       cin >> n;
       long long int arr[n];
       for(int i=0; i<n; i++){
           cin >> arr[i];
           
       if(arr[i]==0){
           cout << 0;
           return 0;
           }
   }
            long long ans = 1LL;
            for(int i=0; i<n; i++){
                if(arr[i]<=1000000000000000000/ans){
                ans*=arr[i];    
            }
                else{
                    ans = -1;
                    break;
                }
       }
       
    cout << ans;   
       return 0;
   }