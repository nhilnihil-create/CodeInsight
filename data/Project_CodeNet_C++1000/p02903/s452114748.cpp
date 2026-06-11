#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int h,w,a,b,i,j,t;
  
  cin >> h >> w >> a >> b;
  
  for (i=0;i<h;i++){
    for (j=0;j<w;j++){
      t=0;
      if (i>=b) t++;
      if (j>=a) t++;
      cout << t%2;
    }
    cout << endl;
  }
  
  return 0;
}