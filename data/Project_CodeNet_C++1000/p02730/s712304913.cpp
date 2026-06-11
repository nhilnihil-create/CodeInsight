#include <bits/stdc++.h>
using namespace std;
 
int main(){
	string s;
  	cin >> s;
  	bool e = true;
  	int a=s.size();
  	for(int i=0;i<(a/2);i++){
    	if(s.at(i) != s.at(a-1-i)){
        	e = false;
          	break;
        }
    }
  int b = (a-1)/2;
  	for(int i=0;i<(b/2);i++){
      if(s.at(i) != s.at(b-1-i)){
      	e = false;
        break;
      } 
    }
  int c=(a+3)/2;
  for(int i = 0;i<((a-1-c)/2);i++){
  	if(s.at(c+i-1) != s.at(a-1-i)){
    	e=false;
      break;
    }
  }
  if(e==true) cout<<"Yes" <<endl;
  else cout << "No" << endl;
}