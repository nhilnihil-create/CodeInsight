#include <bits/stdc++.h>
using namespace std;

int main(){

int N,A,B,C,D;
cin >> N >> D;
C = 0;
//cin >> K >> A >> B;
//vector<int> X(N);
for(int i = 0; i < N;i++){
	cin >> A >> B;
	if(sqrt(pow(A,2)+pow(B,2))<=D) C++;
}
cout << C << endl;
}