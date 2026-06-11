#include <bits/stdc++.h>
using namespace std;
int main() {
 string A;
 cin >> A;
 
 int count = A.size()/2;
  
 if (A.size() % 2 == 0){ 
  for (int i=0;i<A.size()-1;i+=2){
   if (A.at(i) == 'h' && A.at(i+1)=='i'){
   count--; 
   }
   else
     break;
  }
  if (count == 0)
    cout << "Yes" << endl;
  else 
    cout << "No" << endl;
 }
 else
   cout << "No" << endl;
}