#include<iostream>
using namespace std;

int main() {
	int w, h;
	while (1) {
		cin >> h >> w;
		if (w == 0 || h == 0)break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {

				if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)) {
					cout << ".";
				}
				else if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
					cout << "#";
				}

			}
			cout << endl;
		}
          cout<<endl;
	}

}


