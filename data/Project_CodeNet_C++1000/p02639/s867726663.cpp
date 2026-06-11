#include <iostream>
#include <vector>
using namespace std;
int main(){
  vector<int> v(5);
  int i;
  for(i=0;i<5;i++) cin >> v[i];
  for(i=0;i<5;i++){
    if(v[i]==0){
      cout << i+1 << "\n";
      return 0;
    }
  }
}