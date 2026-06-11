#include <iostream>

using namespace std;

main(){
  int a, b, c, d;
  while(cin >> a >> b >> c >> d){
    int sum1, sum2;
    sum1=a+b+c+d;
    cin >> a >> b >> c >> d;
    sum2=a+b+c+d;
    if(sum1>=sum2) cout << sum1 << endl;
    else cout << sum2 << endl;
  }
  return 0;
}