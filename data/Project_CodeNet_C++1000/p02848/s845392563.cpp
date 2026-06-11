#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	string S;
	string Sd;
	cin >> N >> S;
	Sd = S;
	for(int i = 0;i<(int)S.length();i++){
		int num = S[i] - 'A';
		num = (num + N) % 26;
		Sd[i] = 'A' + num;
	}
	cout << Sd << endl;
}