#include <iostream>
using namespace std;

int main(){
  string S;
  string T;
  int seged=0;
  cin >> S;
  cin >> T;
  for (int i=0;i<S.length();i++){
    if(S[i]==T[i]){
     seged+=1; 
    }
  }
  cout << seged;
	return 0;
}
