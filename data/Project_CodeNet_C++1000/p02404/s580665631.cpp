#include<iostream>
using namespace std;

int main(){
	int x[10010];
	int y[10010];
	int i = 0, i2, i3 = 0;
	while (i < 10010){
		cin >> x[i];
		cin >> y[i];
		if (x[i] == 0){
			if (y[i] == 0){
				i2 = i;
				break;
			}
		}
		i++;
	}
	while (i3 < i2){
		for (int i4 = 0; i4 < y[i3]; i4++){
			cout << "#";
		}
		cout << endl;
		for (int i5 = 0; i5 < x[i3] - 2; i5++){
			cout << "#";
			for (int i6 = 0; i6 < y[i3] - 2; i6++){
				cout << ".";
			}
			cout << "#" << endl;
		}
		for (int i7 = 0; i7 < y[i3]; i7++){
			cout << "#";
		}
		cout << endl << endl;
		i3++;
	}
	return 0;
}