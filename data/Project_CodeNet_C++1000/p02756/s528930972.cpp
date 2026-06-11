#include <bits/stdc++.h>
using namespace std;
int main(){
	string S;
	cin >> S;
	string f = "", b = "";
	int which = 0;
	int Q;
	cin >> Q;
	for(int i=0;i<Q;i++){
		int T;
		cin >> T;
		if(T == 1){
			which++;
			which %= 2;
		}
		if(T == 2){
			int F;
			string C;
			cin >> F >> C;
			if((F + which) % 2 == 1)f = f + C;
			else b = b + C;
		}
	}
	reverse(f.begin(), f.end());
	S = f + S + b;
	if(which)reverse(S.begin(), S.end());
	// cout << f << endl;
	// cout << S << endl;
	// cout << b << endl;
	cout << S << endl;
}
