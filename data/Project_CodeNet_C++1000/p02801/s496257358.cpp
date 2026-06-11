#include<bits/stdc++.h>
using namespace std;

int main(){
	string al = "abcdefghijklmnopqrstuvwxyz";
	char a;
	cin >> a;
	for(int i = 0; i<al.size();i++){
		if(al[i]==a){
			cout << al[i+1];
			break;
		}
	}
}