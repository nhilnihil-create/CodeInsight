#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map> // pair
#include <set>
#include <string>

#define MAXSIZE 200000
#define PI 3.141592653589
using namespace std;

template<typename T>
T add(T a,T b){
  return a+b;
}

namespace A
{
  int f(void){
    return 1;
  }
}


int main(){
  int n;
  std::cin >> n;

  for(int i=0;i<n;i++){
    double x1,y1,x2,y2,x3,y3,x4,y4;
    std::cin >> x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    if(abs((x1-x2)*(y3-y4)-(x3-x4)*(y1-y2))<1.0e-10){
      std::cout << "YES" << '\n';
    }else{
      std::cout << "NO" << '\n';
    }
  }
}

