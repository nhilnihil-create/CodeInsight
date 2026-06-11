#include <bits/stdc++.h>
using namespace std;
int main (){
	int cont=1;
	bool band = false;
	string s;
	int pos;
	cin >> s;
	for (int i=1;i<4; i++){
		if (s[i] == s[0]) cont++;
		else if (!band){
			pos = i; band = true;
		}
	}
	if (cont == 2){
		for(int j=pos+1; j<4; j++){
			if (s[pos] == s[j]){
				cout << "Yes";
				return 0;
			}
		}
		cout << "No";
	}
	else{
		cout << "No";
	}
	
	return 0;
}