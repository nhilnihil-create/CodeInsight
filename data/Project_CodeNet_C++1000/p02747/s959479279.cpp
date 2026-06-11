#include <iostream>
#include <string>

using namespace std;
int main(int argc, char** argv){	
  string S;
  cin >> S;
  int len = S.length();
  if(len%2 != 0){
    cout << "No" << endl;
  }
  else{
    string hitachi;
    for(int i=0; i<len/2; i++){
      hitachi += "hi";
    }
    if(hitachi==S)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
