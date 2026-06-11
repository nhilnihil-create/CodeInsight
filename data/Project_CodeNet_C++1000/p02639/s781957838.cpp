#include <bits/stdc++.h>
using namespace std;
 
int main(){
  	int a;
	vector<int> n(5);
  	for(int i=0;i<5;i++){
    	cin >> n.at(i);
  		if(n.at(i) != i + 1) {
          a = i + 1;
			break;
        }
    }
  cout << a << endl;
}