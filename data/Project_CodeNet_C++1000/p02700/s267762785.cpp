#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d;
  	cin >> a >> b >> c>> d;
  	bool e = true;
  	while(e == true){
    	c -= b;
      	
      	if(c <= 0) break;
      	a -= d;
      	if(a <= 0) e = false; 
    }
  	if(e == true) cout << "Yes" << endl;
  	else cout << "No" << endl;
}