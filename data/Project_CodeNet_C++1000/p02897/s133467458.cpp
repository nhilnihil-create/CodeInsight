#include <iostream>
using namespace std;
 
int main() {
	int N;
	cin>>N;
	if(N%2==0){
		cout<<0.5;
	}else{
		cout<<(N+1.0)/(2*N);
	}
}