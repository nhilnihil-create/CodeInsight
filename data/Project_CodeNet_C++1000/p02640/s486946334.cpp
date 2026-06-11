#include <bits/stdc++.h>
using namespace std;

int main(){
	int X,Y;
	cin >> X >> Y;

	bool f=false;
	for(int i=0; i<=100; i++){
		for(int j=0; j<=100; j++){
			if(2*i+4*j == Y && i+j==X)f=true;
		}
	}

	if(f)cout << "Yes" << endl;
	else cout << "No" << endl;

}
