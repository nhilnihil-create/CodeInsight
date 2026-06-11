#include <iostream>
using namespace std;
//Ninda Irvany
int main() {
   int j, k, n, r;
   cin >> n >> r;
   k = 10-n;
   if( n<10 ) {
       cout << r+(100*k) << endl;
   }else{
       cout << r << endl;
   }
}