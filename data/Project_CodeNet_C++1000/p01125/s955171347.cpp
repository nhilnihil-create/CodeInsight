#include <iostream>

using namespace std;

int main(){
	int n, m, map[21][21], x, y;
	while (cin >> n, n){
		for (int i = 0; i < 21; i++){
			for (int j = 0; j < 21; j++){
				map[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++){
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
		}
		cin >> m;
		x = y = 10;
		for (int i = 0; i < m; i++){
			char a;
			int b;
			cin >> a >> b;
			switch (a){
			case 'N':
				for (int j = 0; j < b; j++){
					y++;
					if (map[x][y]){
						map[x][y] = 0;
						n--;
					}
				}
				break;
			case 'E':
				for (int j = 0; j < b; j++){
					x++;
					if (map[x][y]){
						map[x][y] = 0;
						n--;
					}
				}
				break;
			case 'S':
				for (int j = 0; j < b; j++){
					y--;
					if (map[x][y]){
						map[x][y] = 0;
						n--;
					}
				}
				break;
			case 'W':
				for (int j = 0; j < b; j++){
					x--;
					if (map[x][y]){
						map[x][y] = 0;
						n--;
					}
				}
				break;
			}
		}
		if (n){
			cout << "No" << endl;
		} else{
			cout << "Yes" << endl;
		}
	}
	return 0;
}