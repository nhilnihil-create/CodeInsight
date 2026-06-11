#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
   int a,b,c,d;
   cin >> a >> b;
   cin >> c >> d;
   switch(a){
         case 2:
            if(b == 28){
                  cout << 1 << endl;
            }else{
                  cout << 0 << endl;
            }
            break;
         case 4:
         case 6:
         case 9:
         case 11:
            if(b == 30){
                  cout << 1 << endl;
            }else{
                  cout << 0 << endl;
            }
         break;
         default:
            if(b == 31){
                  cout << 1 << endl;
            }else{
                  cout << 0 << endl;
            }
         break;
   }
}
