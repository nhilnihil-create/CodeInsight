#include<iostream>
using namespace std;

char mark(int n){
	if (n % 2 == 0){
		return '#';
	}
	else{
		return '.';
	}
}

int main()
{
	int H, W, count;
	while (cin >> H >> W){
		count = 0;
		if (H == 0 && W == 0){
			break;
		}
		for (int i = 0; i < H; i++){
			for (int j = 0; j < W; j++){
				cout << mark(count++);
			}
			cout << endl;
			if (W % 2 == 0){
				count++;
			}
		}
		cout << endl;
	}
	return 0;
}