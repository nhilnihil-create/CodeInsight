#include <iostream>

using namespace std;
 
int main(){
  int N,D;
  cin >> N >> D;
  if(N%(2*D+1) == 0)
    cout << N/(2*D+1);
  else
    cout << N/(2*D+1)+1;
}