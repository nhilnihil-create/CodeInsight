#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
typedef unsigned int u_i;

int main(){

  	string n;
  	cin >> n;
  	u_i sum=0;
  	for(u_i i=0; i<(u_i)n.size(); ++i){
    	sum += n[i]-'0';
    }
  	if(sum%9==0){
    	cout << "Yes" << endl;  
    }else{
      	cout << "No" << endl;
    }
  
	return 0;
}