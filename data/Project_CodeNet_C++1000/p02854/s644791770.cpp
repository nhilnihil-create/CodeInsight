#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
 int main(){
   long long n;
   cin >> n;
    long long sum=0;
    vector<long long> a(n);
   rep(i,n){
    cin >> a[i];
    sum+=a[i];
   }
    // rep(i,n){
    //   //  cout << a[i] << endl;
    // }

   long long sa=0;
   long long sumf=a[0];
   long long sumsu=a[n-1];
   
   int j=2;
   int d=1;
   rep(i,n-2){
       if(sumf>sumsu){
         sumsu+=a[n-j];
       //  cout << sumsu << "su" << endl;
         j++;
       }
       else{
           sumf+=a[d];
           //cout << sumf << "f" << endl;
           d++;
       }
     
//        sumh+=a[i];
//     if(abs((sum/2)-sumh)<sa && sumh+a[i+1]-sum/2>0){
//         sa=abs(sum-sumh);
//    }
// if(i+1==n/2 && abs(sum/2-(sumh+a[i+1])<sa) && sumh+a[i+1]-sum/2>0){
//     sa=abs(sum/2-(sumh+a[i+1]));
// }
// if(sum==sumh*2){
//     sa=0;
// }
   }
   sa=abs(sumf-sumsu);
   if(sumf==sumsu){
       sa=0;
   }
  cout << sa << endl;
   return 0;
 }