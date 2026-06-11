#include <bits/stdc++.h>
using namespace std;

int main(){
int A,B,C,K;
cin >> A >> B >> C >> K;
if(A>K){
	cout << K <<endl;
	return 0;
}
else if(K>=A && B>K-A){
	cout << A <<endl;
	return 0;
}
else if(K>=A+B && C>K-A-B){
	cout << A-(K-A-B) << endl;
	return 0;
}
else{
	cout << A-C << endl;
}

}