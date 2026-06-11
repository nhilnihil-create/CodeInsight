#include <iostream>
using namespace std;

int main() {
  int A;
  int B;
  cin >> A;
  cin >> B;
  if(A<=B*2){
  cout << "0"; 
  }else{
    cout << A-B*2;
  }
	return 0;
}
