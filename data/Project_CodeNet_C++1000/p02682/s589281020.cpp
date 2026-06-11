#include <iostream>

using namespace std;

int main(){
 int A,B,C,K;
   cin >> A >> B >> C >> K;
  if(K <= A)
  {
   cout << K << endl; 
  }
  if(K <= A+B && K > A)
  {
   cout << A << endl; 
  }
  if(K <= A+B+C && K > A+B)
  {
    cout << 2*A+B-K << endl;
  }
  return 0;
}
