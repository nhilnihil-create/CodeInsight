#include <iostream>
using namespace std;


int main(){
  int n;
  cin >> n;
  int cnt = 0;
  for(int i = 1; i < n/2 + 1; ++i){
    if(i != n - i && n - i > 0){
      cnt += 1;
    }
  }
  cout << cnt << endl;
}
