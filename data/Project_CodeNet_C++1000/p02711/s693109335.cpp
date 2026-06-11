#include<iostream>
using namespace std;

int main(){
  string n;
  cin >> n;
  
  for (int i = 0;i < n.size(); i++){
    if (n[i] == '7'){
      cout << "Yes" << endl;
      break;
    }
    if (i + 1 == n.size()){
      cout << "No" << endl;
    }
  }
 
  return 0;
}
