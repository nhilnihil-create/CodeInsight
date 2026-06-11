#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int k,a,b;
  	cin >> k >> a >> b;
  	bool e = false;
  	for(int i=a;i<=b;i++){
    	if(i % k == 0) e = true;
    }
  	if(e == true) cout <<"OK" << endl;
  	else cout << "NG" << endl;
}