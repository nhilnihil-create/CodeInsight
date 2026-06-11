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
   string m,l;
  
   cin >> n >> m >> l;
   
   for(int i = 0;i<n;i++){
     
     if(i!=n-1){
        cout << m[i] << l[i];
     }else{
       cout << m[i] << l[i] << endl;

     }
   }
   
   
  return 0;
}
