#include <iostream>
using namespace std;

int main() {
	int A;
  int B;
  cin >> A;
  cin >> B;
  if(A<10){
    if(B<10){
      cout << A*B;
    }else{
      cout << "-1";
    }
  }else{
    cout << "-1";
  }
	return 0;
}
