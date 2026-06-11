#include <bits/stdc++.h>
 using namespace std;
  int main (){
      long long x,n=0;
      cin >> x;
      long long sum=100;
       while(sum<x){
       sum+=(sum/100);
        n++;
       }
       cout << n << endl;
      }