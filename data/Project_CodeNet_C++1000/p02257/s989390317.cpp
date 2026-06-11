#include<iostream>
#include<cmath>
using namespace std;

int prime(int x);

int main() {
    int n; //how many numbers
    int x;
    int cou = 0;
    
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> x; //stop endl
        cou += prime(x);
    } 
    cout << cou << endl;
    
    return 0;
}

int prime(int x) {
  int c = 0;
  
  if (x <= 1) return c;
  else if (x == 2) return ++c; //c++ だとreturnして++
  else {
      for ( int i = 2; i <= sqrt(x); i++ ) {
          if (x % i == 0) return c;
      }
      return ++c;
  }
}
