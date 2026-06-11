#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  int osatsu = 0;
   
  while(osatsu*1000 < N){
    osatsu++;
  }
  cout << osatsu*1000 - N << endl;
}