#include <iostream>
using namespace std;

int main(){
	int H[25565] = {0};
	int W[25565] = {0};
	int i;
	do{
		cin >> H[i] >> W[i];
		i++;
		}while(H[i-1] != 0 && W[i-1] != 0);
	i = 0;
	do{
		for(int j=0;j<W[i];j++){
			cout << "#";
		}
		cout << endl;
		for(int j=0;j<H[i]-2;j++){
			cout << "#";
			for(int k=0;k<W[i]-2;k++){
				cout << ".";
			}
			cout << "#" << endl;
		}
		for(int j=0;j<W[i];j++){
			cout << "#";
		}
		cout << endl << endl;
		i++;
	}while(H[i] != 0 && W[i] != 0);
}