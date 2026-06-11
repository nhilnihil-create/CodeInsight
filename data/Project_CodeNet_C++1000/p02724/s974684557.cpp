#include <iostream>
using namespace std;

int main() {
  int yen;
  cin >> yen;
  int ans=0;
  int temp=yen/500;
  ans+=(temp*1000);
  temp=yen%500;
  temp=temp/5;
  ans+=(temp*5);
  cout << ans << endl;





}