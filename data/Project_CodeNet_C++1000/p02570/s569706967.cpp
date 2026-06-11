#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
 
int main() {
  //input
  int d,t,s;cin >> d >> t >> s;
  bool ans;
  
  //compute
  if(d % s == 0){
           ans = ((d / s) <= t);
         }else{
           ans = ((d / s) < t);
         }
 
  //output
  if(ans == true){
           cout << "Yes" << endl;
         }else{
           cout << "No" << endl;
         }
  
}