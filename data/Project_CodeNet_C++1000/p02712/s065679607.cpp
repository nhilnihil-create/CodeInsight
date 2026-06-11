#include <iostream>
#include<stdio.h>
using namespace std;
#define int long long

signed main(){
    // Your code here!
   int n;
   int sum = 0;
   cin >> n;
   for(int i=1; i <=n; i ++){
       if( i%3 != 0 && i%5 != 0 ){
           sum += i;
       }
   }
   cout << sum;
}
