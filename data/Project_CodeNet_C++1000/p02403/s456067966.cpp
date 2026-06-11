#include<iostream>
using namespace std;

struct rect{
	int h;
	int w;
};

int main()
{
	rect rec;

	for (int k = 0;; k++){

		cin >> rec.h >> rec.w;

		if (rec.h == 0 && rec.w == 0)
			break;

		for (int i = 0; i < rec.h; i++){
			for (int j = 0; j < rec.w; j++){
				cout << '#';

			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}