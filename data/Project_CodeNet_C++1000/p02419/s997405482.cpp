#include<iostream>
#include<string>
using namespace std;

int main() {
	
	string A,C;
	int count = 0;
	
	cin >> A;
	
	for(int i=0;i<A.length();i++)
	if( A[i] >= 'a' )
	A[i] -= 32;
	
	while( cin >> C) {
	
	if ( C == "END_OF_TEXT")
	break;
	
	for(int i=0;i<C.length();i++)
	if( C[i] >= 'a' )
	C[i] -= 32;
	
	if( A == C)
	count++;

}
	cout << count << "\n";
	return 0;
}
