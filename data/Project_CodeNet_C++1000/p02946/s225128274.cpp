#include<bits/stdc++.h>
using namespace std;

int main(){
   int K,X;
   cin >> K >> X;
   int k = K - 1;
   int kk = k + K;
   int x = X - k;
   for(int i=0;i<kk;i++){
       cout << x << " ";
       x++;
   }
   return 0;
}