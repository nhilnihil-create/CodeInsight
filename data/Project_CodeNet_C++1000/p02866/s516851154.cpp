#include <bits/stdc++.h>
using namespace std;
long myPow(long x, long n, long m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}
int main(){
   long long n, i, ans=1, cnt[100101]={0}, max=-1;
   cin >> n;
   for(i=0;i<n;i++){
       long long tmp;
       cin >> tmp;
       if(i==0 && tmp!=0) ans=0;
       if(tmp>max) max=tmp;
       cnt[tmp]++;
   }
   if(ans==0){
       cout << ans <<endl;
       return 0;
   }
   else if(cnt[0]>=2) ans=0;
   else{
       for(i=2;i<=max;i++){
        ans=ans*myPow(cnt[i-1], cnt[i], 998244353);
        ans=ans%998244353;
       }
   }
   cout << ans <<endl;
    return 0;
}
