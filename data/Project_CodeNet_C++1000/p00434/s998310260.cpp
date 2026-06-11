#include <bits/stdc++.h>
using namespace std;

int main(){
	bool b[31];
	for(int i=0; i <= 30; i++) b[i] = true;
	b[0] = false;
	for(int i=0; i < 28; i++){
		int in;
		cin>> in;
		b[in] = false;
	}
	for(int i=0; i <= 30; i++){
		if(b[i]) cout << i << endl;
	}
}