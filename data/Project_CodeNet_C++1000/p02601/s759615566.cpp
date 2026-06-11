#include <iostream>
#include <vector>
using namespace std;

bool getResult(int redNum, int greenNum, int blueNum, int count){
  if(count == 0) return ((redNum < greenNum) && (greenNum < blueNum));

  bool result;
  result = getResult(redNum * 2, greenNum, blueNum, count - 1);
  if(result) return result;

  result = getResult(redNum, greenNum * 2, blueNum, count - 1);
  if(result) return result;
  
  result = getResult(redNum, greenNum, blueNum * 2, count - 1);
  return result;
}

int main(){
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  
  string result = getResult(A, B, C, K)? "Yes" : "No";  
  cout << result << endl;
  return 0;
}