#include <iostream>
using namespace std;

int main() {
	int M,D;
	cin>>M>>D;
	int cont= 0;
	for(int i=1;i<=M;i++){
		for(int j=10;j<=D;j++){
			if((j/10)*(j%10) == i && j/10 >=2 && j%10 >=2){
				cont++;
			}
		}
	}
	cout<<cont;
	return 0;
}