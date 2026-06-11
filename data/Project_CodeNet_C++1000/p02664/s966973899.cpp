#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
  string data;
  cin >> data;
  
  for(int i=0;i<(int)data.size();i++){
	if(data.substr(i, 1)=="?"){
		data.replace(i, 1, "D");
    }
  }
 
  cout << data << endl;
  return 0;
}