#include <iostream>
using namespace std;

int main() {
int A;
int B;
int C;
cin >> A;
cin >> B;
cin >> C;
if(A==B&&A==C){
  cout << "No";
}else if(B==C){
  cout << "Yes";
}else if(A==C){
  cout << "Yes";
}else if(A==B){
  cout << "Yes";
}else{
  cout << "No";
}
	return 0;
}
