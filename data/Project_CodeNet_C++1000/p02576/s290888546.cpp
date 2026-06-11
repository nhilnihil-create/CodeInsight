#include<iostream>

using namespace std;

int main(){
  int x, t, n, counter;
  cin >> n >> x >> t;

  counter = 0;
  while(n > 0){
    n -= x;
    counter++;
  }
  cout << t * counter << endl;
  
}
