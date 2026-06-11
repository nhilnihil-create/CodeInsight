#include <bits/stdc++.h>
using namespace std;
 
int main(){
int A=0, T=0, R=0, N = 0, K = 1;
int X, Y;
//vector<int> M(5);
cin >> X >> Y;
if(Y%2==1){
	cout << "No" << endl;
	return 0;
}
for(int i = 0; i <= X; i++){
	if(i*2+(X-i)*4==Y){
		cout << "Yes" << endl;
		return 0;
	}
}

cout << "No" << endl;

}