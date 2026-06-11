#include<iostream>
using namespace std;
int main() {
	//abc147_c
	int n;
	cin >> n;
	int bin[17];
	bin[0] = 1;
	int i, j, k;
	int x[16][16], y[16][16], a[16];
	for (i = 0; i < n; i++) {
		cin >> a[i];
		for (j = 0; j < a[i]; j++) {
			cin >> x[i][j] >> y[i][j];
			x[i][j]--;
		}
	}
	//cout << y[0][0] << ' ' <<y[1][0] << ' ' << y[2][0] << endl;
	int maxo = 0, c, flag, flag2;

	for (i = 1; i <= 16; i++)bin[i] = 2 * bin[i - 1];
	for (i = bin[n] - 1; i >= 0; i--) {
		c = 0;
		flag = 0;
		for (j = 0; j < n; j++) {
			if ((i ^ bin[j]) != (i + bin[j])) {
				c++;
				
			}
			//if (flag == 1)break;
		}
		if (c < maxo) {
			flag = 1;
		}
		//cout << "c = " << c << ", flag = " << flag << endl;
		flag2 = 0;
		if (flag == 0) {

			for (j = 0; j < n; j++) {
				if ((i ^ bin[j]) != (i + bin[j])) {
					//j番は正直者
					//cout << "i = " << i << ". j = " << j << endl;
					for (k = 0; k < a[j]; k++) {
						//cout << "i = " << i << ". j = " << j << endl;
						if (y[j][k] == 1) {
							if ((i ^ bin[x[j][k]]) == (i + bin[x[j][k]])) {
								flag2 = 1;
								//cout << "i = " << i << ", j = " << j << ", k = " << k << endl;
							}
						}
						else {
							if ((i ^ bin[x[j][k]]) != (i + bin[x[j][k]])) {
								flag2 = 1;
								//cout << "i = " << i << ", j = " << j << ", k = " << k << endl;
							}
						}
					}
				}
			}
			//cout << "i = " << i << ", c = " << c << ", flag2 = " << flag2 << endl;

			if (flag2 == 0) {
				maxo = c;
			}
		}
		//cout << "i = " << i << ", c = " << c << ", flag2 = " << flag2 << endl;
		//cout << "maxo = " << maxo << endl;



	}
	cout << maxo << endl;
	return 0;

}