#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int nax = 1e6+1;


int main(){

   ll n;
   cin>>n;
   ll mi = 2*n;
   for(ll i=1;i*i<=n;i++){
    if(n%i==0){
        ll k = n/i;

        ll sum = i+k;
        mi = min(mi,sum);
    }
   }
cout<<mi-2;

return 0;
}

