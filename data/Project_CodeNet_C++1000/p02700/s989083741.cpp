#include <bits/stdc++.h>
using namespace std;

int main(){
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int chk = 1;
	while(A > 0 && C > 0){
		if(chk) C -= B;
		else A -= D;
		chk++;
		chk %= 2;
	}
	if(A <= 0) cout << "No" << endl;
	else cout << "Yes" << endl;
}
