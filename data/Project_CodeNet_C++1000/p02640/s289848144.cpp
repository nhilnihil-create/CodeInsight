#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main(){
  int X, Y;
  cin >> X >> Y;
  if(2*X<=Y&&Y<=4*X&&Y%2==0){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}