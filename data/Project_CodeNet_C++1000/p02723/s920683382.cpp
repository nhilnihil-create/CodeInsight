#include <iostream>
using namespace std;

int main() { 
  string S="coffee";
  cin >> S;
  if(S[2]==S[3] && S[4]==S[5]){
    cout << "Yes";
  }else{
    cout << "No";
  }
	return 0;
}
