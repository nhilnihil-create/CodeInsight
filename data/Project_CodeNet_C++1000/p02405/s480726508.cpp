#include <iostream>
using namespace std;

int main(){
	int H[25565] = {0};
	int W[25565] = {0};
	int i = 0;
	do{
		cin >> H[i] >> W[i];
		i++;
	}while(H[i-1] != 0 && W[i-1] != 0);
	i = 0;
	do{
		for(int j=0;j<H[i];j++){
			for(int k=0;k<W[i];k++){
				if((j+k) % 2 == 0){
					cout << "#";
				}else{
				cout << ".";
				}
			}
			cout << endl;
		}
		cout << endl;
		i++;
	}while(H[i] != 0 && W[i] != 0);
}