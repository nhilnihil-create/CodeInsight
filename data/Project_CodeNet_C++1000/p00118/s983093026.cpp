#include <iostream>
#include <string>

using namespace std;

int h, w;
int field[100][100];

void deleteField(int x, int y, int fluit);
void Delete(int x, int y, int f);

int main() {
	int ans;
	string str;

	/*??\???*/
	cin >> h >> w;

	ans = 0;
	while (h && w) {
		for (int i = 0; i < h; i++) {
			/*????????¨?????\????????´??°???2?¬???????????????????*/
			cin >> str;

			for (int j = 0; j < w; j++) {
				switch (str[j]) {
					case '@':
						field[i][j] = 1;
						break;
					case '#':
						field[i][j] = 2;
						break;
					default:
						field[i][j] = 3;
				}
			}
		}

		/*???????????????????????????????????????????????????????????????????¶????*/
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (field[i][j] != 0) {
					ans++;
					deleteField(j, i, field[i][j]);

					/* Debug //
					for (int k = 0; k < h; k++) {
						for (int l = 0; l < w; l++) {
							cout << field[k][l];
						}
						cout << endl;
					}
					cout << "-----\n";

					getchar();
					//////////*/
				}

			}

		}

		cout << ans << endl;

		ans = 0;
		cin >> h >> w;
	}


}

void deleteField (int x, int y, int fruit) {
	field[y][x] = 0;

	if (x - 1 >= 0) {
		Delete(x-1, y, fruit);
	}
	if (x + 1 < w){
		Delete(x+1, y, fruit);
	}
	if (y - 1 >= 0) {
		Delete(x, y-1, fruit);
	}
	if (y + 1 < h) {
		Delete(x, y+1, fruit);
	}
}

void Delete(int x, int y, int f) {
	if (field[y][x] == f) {
		deleteField(x, y, f);
	}
}