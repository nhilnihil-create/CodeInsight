#include <iostream>
using namespace std;

int main()
{
	int mansion[4][3][10] = {0};
	int b,f,r,v,count;
	int i = 0;
	cin >> count;

	while(i < count){
		cin >> b >> f >> r >> v;
		mansion[b - 1][f - 1][r - 1] += v;
		i++;
	}

	for(int j = 0; j < 4; j++){
		for(int h = 0; h < 3; h++){
			for(int k = 0; k < 10; k++){
				cout << ' ' << mansion[j][h][k];
			}
			cout << endl;
		}
		if(j != 3){cout << "####################" << endl;}
	}

	return 0;
}