//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
  
   int isValid(int mid,int k,int a[],int n){
       int i,j;
       if(mid == 0) return 0;
       for(i = 0;i<n;i++){
           if(a[i]  <= mid) continue;
           int tt = a[i] / mid;
           k -= tt;
       }
       if(k>=0) return 1;
       else return 0;
   }
int main(){
    
    int i,j,n,k;
    cin >> n >> k;
    int a[n];
    
    for(i = 0;i<n;i++) cin >> a[i];
    
    int low,high,mid,temp;
    
    low = -1;
    high = 1e9 + 10;
    while(high - low > 1){
        mid = (low + high)/2;
        if(isValid(mid,k,a,n)) high = mid;
        else low = mid;
    }
      cout << high << endl;
    return 0;
}


