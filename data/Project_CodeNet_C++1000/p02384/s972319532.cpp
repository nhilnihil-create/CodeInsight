#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

class dice {
public:
	int face[7];
	int get;

	dice(int x[]) {
		for (int i = 1; i <= 6; i++)
			face[i] = x[i];
	}

	int makesure(int above, int front,dice c) {
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 4; j++) {
				if (c.face[1] == above && c.face[2] == front) {
					return c.face[3];
				}

				c.roll();
			}
			if(i%2)c.round('W');
			else c.round('N');
		}
		return -1;
	}

	void roll() {
		get = face[2];
		face[2] = face[3];
		face[3] = face[5];
		face[5] = face[4];
		face[4] = get;
	}

	void round(char x) {
			switch (x) {
			case 'E':
				get = face[1];
				face[1] = face[4];
				face[4] = face[6];
				face[6] = face[3];
				face[3] = get;
				break;
			case 'W':
				get = face[1];
				face[1] = face[3];
				face[3] = face[6];
				face[6] = face[4];
				face[4] = get;
				break;
			case 'N':
				get = face[1];
				face[1] = face[2];
				face[2] = face[6];
				face[6] = face[5];
				face[5] = get;
				break;
			case 'S':
				get = face[1];
				face[1] = face[5];
				face[5] = face[6];
				face[6] = face[2];
				face[2] = get;
				break;
			}
		}
};

int main() {
	int facef[7];
	int q;

	for (int i = 1; i <= 6; i++) {
		cin >> facef[i];
	}

	dice dice1(facef);

	cin >> q;

	int above, front;

	for (int i = 0; i < q; i++) {
		cin >> above >> front;

		cout << dice1.makesure(above, front, dice1) << endl;
	}

	return 0;
}