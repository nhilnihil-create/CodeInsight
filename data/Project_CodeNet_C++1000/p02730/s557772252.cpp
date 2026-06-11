#include <bits/stdc++.h>
using namespace std;

int main(){
int t=0;
string s;
cin >> s;
int N = s.length();
int M = (N-1)/2;
for(int i=0;i<(N-1)/2;i++){
	if(s.at(i) != s.at(N-1-i)){
		cout << "No" << endl;
		return 0;
	}
}
for(int i=0;i<(N+1)/4;i++){
	if(s.at(i) != s.at(M-1-i)){
		cout << "No" << endl;
		return 0;
	}
}
for(int i=(N+3)/2-1;i<N;i++){
	if(s.at(i) != s.at(N-1-i)){
		cout << "No" << endl;
		return 0;
	}
}

cout << "Yes" << endl;
}