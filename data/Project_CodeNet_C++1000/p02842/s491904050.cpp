#include <iostream>
#include <vector>
using namespace std;
int main(void){
   int n;
   cin >> n;
   for(int i = 1;i <= n;i++){
       if(i * 108 / 100 == n){
           cout << i << endl;
           return 0;
       }
   }
   cout << ":(" << endl;
}
