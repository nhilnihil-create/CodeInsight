#include <iostream>
#include <string>
using namespace std;
 
int main() {
	int A, B, C;
	cin>>A>>B>>C;
	if(A+B+C>=22){
		cout<<"bust";
	}else
		cout<<"win";
}