#include <bits/stdc++.h>
using namespace std;
map<long long, long long> mp;
int divideprime(long long n){
    long long i=2;
    for(i=2;i<=sqrt(n)+1;i++){
        while(n%i==0){
            n/=i;
            mp[i]++;
        }
    }
    if(n!=1) mp[n]++;
    return 0;
}
int main(){
   long long n, ans=0, cnt=1;
   cin >> n;
   divideprime(n);
   for(auto x : mp){
       while(1){
           if(x.second>=cnt){
               x.second-=cnt;
               ans++;
               cnt++;
            }
            else break;
        }
        cnt=1;
   }
   cout << ans <<endl;
   return 0;
}