#include<iostream>
using namespace std;
int main()
{
	int H[100000], W[100000];
	int i,j,r,d;
	for (i = 0; i < 98000; i++){
		cin >> H[i] >> W[i];
		if (H[i] == 0 && W[i] == 0){
			j = i;
			break;
		}
	}
	for (i = 0; i < j; i++){
		for (r=0;r<H[i];r++){
			for (d=0;d<W[i];d++){
				if ((r % 2) != 0 && (d % 2) != 0){
					cout << "#";
				}
				else if ((r% 2) == 0 && (d% 2) == 0){
					cout << "#";
				}
				else{
					cout << ".";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}