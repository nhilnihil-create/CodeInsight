#include <bits/stdc++.h>
 
using namespace std;
//#define int long long


 const int MAX = 1001;
const int MOD = 1000000007;



signed main(){
    int n;
    
    cin>>n;
    int m=0;
   while(n>(1<<m))m++;
   int k;
   for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
           k=m-1;
           while((i^j)<(1<<k))k--;
           cout<<k+1<<' ';
       }
       cout<<endl;
   }

   return 0;
}