#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
   ll N,A;
   cin >> N;
   map<ll,ll> data;
   bool over=false;
   for (int i=0;i<N;i++){
       cin >> A;
       data[A]++;
       if(data[A]==2){
           over=true;
           break;
       }
   }
   if(over==true){
       cout << "NO" << endl;
   }
   else{
       cout << "YES" << endl;
   }
}
