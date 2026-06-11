#include <iostream>
#include <math.h>

int arr1[10] = {0,1,2,3,4,5,6,7,8,9};
int arr3[10] = {0,7,4,1,8,5,2,9,6,3};
int arr7[10] = {0,3,6,9,2,5,8,1,4,7};
int arr9[10] = {0,9,8,7,6,5,4,3,2,1};

int getNumber(int a, int b){
  switch(a){
    case 1:
      return arr1[b];
      break;
    case 3:
      return arr3[b];
      break;
    case 7:
      return arr7[b];
      break;
    case 9:
      return arr9[b];
      break;
    default:
      return -1;
      break;
  }
}

int main(){
  long k, c, r;
  std::cin >> k;
  int m = k % 10;
  c = 0;r = k;
  while(r > 0){
    if(c==0)r = k;
    int n = getNumber(m, (17 - r % 10) % 10);
    if(n == -1) {
      c = -1;
      break;
    }
    r += n * k;
    r /= 10;
    c++;
   // std::cout << r << std::endl;
  }
  
  std::cout << c << std::endl;
}


