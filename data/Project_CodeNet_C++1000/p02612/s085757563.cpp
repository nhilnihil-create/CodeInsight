#include <iostream>
using namespace std;

int main(){
	long N;
	cin>>N;
	int charge;

	for(int i=1;(i-1)*1000<N;i++){
		if(i*1000>=N)charge=i*1000-N;
	}
	cout<<charge<<endl;
}