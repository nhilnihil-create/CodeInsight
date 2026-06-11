#include <iostream>
#include <set>
using namespace std;

int main(){
  int N;
  set<string> gacha;
  
  cin >> N;
  for(int i= 1;i<=N;i++){
    string input;
    cin >> input;
    gacha.insert(input);
  }
  cout << gacha.size() << endl;
  
    
  return 0;
}