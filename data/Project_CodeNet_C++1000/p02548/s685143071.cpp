#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;int result=0;
  for(int i=1;i<n;++i){
    for(int j=1;i*j<n;++j){
      result++;
    }
  }
  cout << result << endl;
  return 0;
}