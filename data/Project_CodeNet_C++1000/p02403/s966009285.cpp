#include<iostream>

using namespace std;
int main(){
	int h = 0;
	int w = 0;
	while (1){
		cin >> h >> w;
		if (h == 0 && w == 0){
			break;
		}
		for (int i = 0; i < h; i++){
			for (int it = 0; it < w; it++){
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}