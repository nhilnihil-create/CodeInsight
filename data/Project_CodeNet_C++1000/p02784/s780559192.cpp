#include <bits/stdc++.h>
using namespace std;
int main(){
   int h, n, temp;
   cin >>h >>n;
   for(int i =0; i <n; ++i){
       cin >> temp;
       h -= temp;
   }
   if(h>0){
       cout<<"No";
   }
   else{
       cout<< "Yes";
   }
}