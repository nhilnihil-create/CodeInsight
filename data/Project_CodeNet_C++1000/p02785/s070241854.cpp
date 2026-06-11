#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
   ll N,K,sum=0;
   cin >> N >> K;
   vector<ll> A(N);
   if(K>=N){
       cout << 0 << endl;
   }
   else{
   for(int i=0;i<N;i++){
       cin >> A[i];
       sum+=A[i];
   }
   sort(A.begin(),A.end());
   reverse(A.begin(),A.end());
   for(int i=0;i<K;i++) {
       sum-=A[i];
   }
   cout << sum << endl;
   }
}
