#include <iostream>
using namespace std;

int main(){
	
	bool flag = true;
	while (flag == true){
		int h, w = 0;
		cin >> h >> w;
		if (h != 0 && w != 0){
			for (int i = 0; i < h; i++){
				for (int j = 0; j < w; j++){
					if ((i+j) % 2 == 0){
						cout << "#";
					}
					else{
						cout << ".";
					}
				}
				cout << endl;
			}
			cout << endl;
		}
		else{
			flag = false;
		}
	}

}