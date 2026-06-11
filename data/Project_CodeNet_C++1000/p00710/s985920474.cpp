#include <iostream>
#include <math.h>
#include <array>
#include <algorithm>
using namespace std;
int n, r, p, c;

int main(){
  while( cin >> n >> r && n > 0){
    int a[50];
    for(int i = 1; i < n+1; i++){
      a[i-1] = i;
    }
    for (int i = 0; i < r; i++){
      cin >> p >> c;
      rotate(a+n+1-c-p, a+n+1-p, a+n);
    }


    cout << a[n-1] << endl;


  }




}
