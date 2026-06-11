#include <iostream>
#include <string>
using namespace std;

int main() {
 string A;
 cin>> A;

 if(A[0]==A[1] && A[1]!=A[2] && A[2]==A[3])cout << "Yes" << endl;
  else if(A[0]==A[2] && A[1]!=A[2] && A[3]==A[1])cout << "Yes" << endl;
  else if(A[0]==A[3] && A[1]==A[2] && A[3]!=A[1])cout << "Yes" << endl;
  else cout << "No" << endl;
}
