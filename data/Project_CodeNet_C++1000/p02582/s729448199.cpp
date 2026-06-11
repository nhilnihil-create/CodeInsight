#include <bits/stdc++.h>
using namespace std;

int main(){

int N,A,B,C,D;
B=0;
C=0;
char c;
//cin >> N >> D;
//cin >> K >> A >> B;
//vector<int> X(N);

for(int i = 0; i < 3;i++){
	cin >> c;
	if(c == 'R') C++;
	if(i==1 && c=='S') B=1;
}
if(B==1 && C==2) cout << 1 << endl;
else cout << C << endl;
}