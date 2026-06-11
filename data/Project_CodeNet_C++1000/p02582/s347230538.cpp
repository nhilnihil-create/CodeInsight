#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

	string s;
  	int mx=0,pr=0;
  	cin >> s;
  	for(int i=0; i<3; ++i){
      if(s[i]=='R'){
        if(pr==0){
			mx = max(mx,1);
          	pr++;
        }else{
			mx = max(mx,pr+1);
          	pr++;
        }
      }else{
        pr = 0;
      }
    }
  
  	cout << mx << endl;
	return 0;
}