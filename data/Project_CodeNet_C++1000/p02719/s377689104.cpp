#include <bits/stdc++.h>
using namespace std;


int main(void){
   int64_t N,K;
   cin >> N >> K;
   
   int64_t r=N%K;
   if (r>abs(r-K)) {
       cout << abs(r-K) << endl;
   }
   else {
       cout << r << endl;
   }
   
}


