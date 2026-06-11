#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int euqrid(int a,int b){
      return (a % b == 0) ? b : euqrid(b,a % b);
}
int main(void){
   int x;
   cin >> x;
   cout << 360 / euqrid(360,x) << endl;
}
