#include <iostream>
#include <cstring>
using namespace std;
int main(){
	string S, T; cin >> S >> T;
	
	int kotae = 10000000;
	for(int i=0; i<S.size() - T.size() + 1; i++){
		int cnt = 0;
		for(int j=0; j<T.size(); j++){
			if(S[i+j] != T[j]) cnt++;
		}
		kotae = min(cnt, kotae);
	}  	
  
  	cout << kotae << endl;
  
  return 0;
}
