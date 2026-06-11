#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
   for (int i = 0; i < 3; i++) {
     char a;
     char b;
     a = S.at(i);
     b = S.at(i+1);{
       if( a == b){
         cout << "Bad" << endl;
         break;}
       else if (i == 2)
              cout <<  "Good" <<endl;
     }
   }
}
