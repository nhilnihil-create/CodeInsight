#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
   int a,b,c,d,k;
   cin >> a >> b >> c >> d >> k;
   
   cout << (c * 60 + d) - (a * 60 + b) - k << endl;
}
