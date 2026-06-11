#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
  	cin >> s;
  	int rainy = 0;
  	int maxrainy = 0;
  	for(int i=0;i<3;i++){
    	if(s[i] == 'R'){
        	rainy++;
        } else {
        	rainy = 0;
        }
      	if(rainy > maxrainy){
        	maxrainy = rainy;
        }
    }
  	cout << maxrainy << endl;
}