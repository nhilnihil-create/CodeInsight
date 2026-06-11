#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main(){
  char alpha;
  cin >> alpha;
  int x = alpha - 'a';
  if(x>=0){
    cout << "a";
  }else{
    cout << "A";
  }
  return 0;
}