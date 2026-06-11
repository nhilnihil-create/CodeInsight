#include <functional>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int main() {
   int n;
   string m;
   cin >> n >> m;
   int sum = 0;
   char tmp;
   int flag = 0;
  
   for(int i = 0;i<n;i++){
     
     
   //  cout << tmp << endl;
     
     if (tmp!=m[i]){
       sum = sum + 1;
       flag = 0;
     }
     
     if(flag ==0){
     tmp = m[i];
       flag = 1;
     }
     
   }
  
  cout << sum;
   
  return 0;
}