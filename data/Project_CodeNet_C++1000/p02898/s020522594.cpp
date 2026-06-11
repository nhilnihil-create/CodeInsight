#include <bits/stdc++.h>
using namespace std;
int main(void){
   
   int N,K,c=0;
   cin >> N >> K;
   
   for(int i=0;i<N;i++){
       int h_i;
       cin >> h_i;
       if(h_i >= K) c++;
   }
   cout << c <<endl;
}