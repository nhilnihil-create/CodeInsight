#include<iostream>
#include<string>
#include <numeric>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> P;

int main(){
  int x, y;
  cin >> x >> y;
  for(int i=0; i<=x; i++){
    if((i*2 + (x-i)*4) == y){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}