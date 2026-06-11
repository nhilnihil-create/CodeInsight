#include<iostream>
#include<string>
#include <numeric>
#include <algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> P;

int main(){
  int x;
  for(int i=0; i<5; i++){
    cin >> x;
    if(x != i+1){
      cout << i+1 << endl;
      return 0;
    }
  }
}