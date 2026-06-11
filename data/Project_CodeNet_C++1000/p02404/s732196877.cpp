#include<iostream>
using namespace std;

int main()
{
	int H = 0, W = 0, count = 0, a[10000] = { 0 };
	while (1){
		cin >> H >> W;
		if (H == 0 && W == 0) break;
		a[count] = H, a[++count] = W;
		count++;
	}
	int i = 0;
	while (i < count){
		for (int j = 0; j < a[i + 1]; j++) cout << "#";
		cout << endl;
		for (int j = 1; j < a[i] - 1; j++){
			for (int k = 0; k < a[i + 1]; k++){
				if (k == 0 || k == a[i + 1] - 1) cout << "#";
				else							 cout << ".";
			}
			cout << endl;
		}
		for (int j = 0; j < a[i + 1]; j++) cout << "#";
		cout << endl;
		cout << endl;
		i += 2;
	}
	return 0;
}