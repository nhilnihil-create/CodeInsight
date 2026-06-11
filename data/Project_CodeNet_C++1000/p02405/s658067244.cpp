
#include<iostream>

using namespace std;

int main(){

	int h, w;

	while (true){

		cin >> h >> w;

		if (h == 0 && w == 0)break;

		for (int i = 0; i <= h - 1; i++){

			for (int j = 0; j <= w - 1; j++){

				if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)){
					cout << '#';
				}
				else{
					cout << '.';
				}

			}

			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
