#include <bits/stdc++.h>
using namespace std;
int main(void){
   string N;
   cin >> N;
   bool seven=false;
   for (int i=0;i<3;i++) {
        if(N[i]=='7') {
            seven = true;
            break;
        }
        
   }
   if(seven==true) {
       cout << "Yes" << endl;
   }
   else {
       cout << "No" << endl;
   }
} 
