#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
  	bool flg = true;
  
  	cin >> N;
  	vector<int> num(N);
  
  	for(int i; i < num.size(); i++){
      	cin >> num.at(i);
      
      	if(num.at(i) % 2 == 0){
      		if(!(num.at(i) % 3 == 0 || num.at(i) % 5 == 0)){
          		cout << "DENIED" << endl;
          		flg = false;
        		break;
        	}
        }
    }
    
    if(flg){
    	cout << "APPROVED" << endl;
    }
  
	return 0;
}