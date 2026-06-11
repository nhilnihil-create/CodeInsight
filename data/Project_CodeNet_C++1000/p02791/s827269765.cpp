#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;

int main(void){
   ll N,P;
   cin >> N;
   ll cnt=0;
   ll c=1000000000;
   
   rep(i,N){
       cin >> P;
       if(min(c,P)==P){
           cnt++;
       }
       c=min(c,P);
   }
   cout << cnt << endl;
}
