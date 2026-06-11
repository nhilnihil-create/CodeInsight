#include <iostream>
using namespace std;
 
int main() {
	int A, B, C;
	cin>>A>>B>>C;
	if(A>=B && A>=C) {
		cout<<B+C;
	} else if(C>=B && C>=A){
		cout<<A+B;
	} else if(B>=A && B>=C){
		cout<<C+A;
	}
	return 0;
}