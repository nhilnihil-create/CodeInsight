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
		for (int i4 = 0; i4 < x[i3]; i4++){
			for (int i5 = 0; i5 < y[i3]; i5++){
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
		i3++;
	}
	return 0;
}