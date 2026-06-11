#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  int num;
  cin >> num;
  string k;
  cin >> k;
  if(k.size()>num){
    string ans;
    for(int i = 0;i < num;i++){
      ans.insert(ans.begin()+i,k[i]);
    }
    cout << ans << "..." << endl;
  }else{
    cout << k << endl;
  }
  return 0;
}