#include <bits/stdc++.h>
using namespace std;

int main(){
int N,A,B,C=0,K,d;
cin >> K >> A >> B;
//vector<int> A(N);

for(int i = A;i <= B; i++){
	if(i%K==0){
		C++;
		break;
	}
}
if(C == 1) cout << "OK" << endl;
else cout << "NG" << endl;
}