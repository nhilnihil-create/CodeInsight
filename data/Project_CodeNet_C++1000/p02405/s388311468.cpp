#include <iostream>
using namespace std;

int main(){
	int a,b;
	while(1){	
		if(a == 0&&b == 0){
			break;
		}
		cin >> a >> b;
		for(int i = 1; i <= a; i++){
			if(i%2 != 0){
				for(int j = 1; j <= b; j++){
					if(j%2 == 0){
						cout << ".";
					}
					else{
						cout << "#";
					}
				}
				cout << endl;
				if(i == a){
					cout << endl;
				}
			}
			else if(i%2 == 0){
				for(int j = 1; j <= b; j++){
					if(j%2 == 0){
						cout << "#";
					}
					else{
						cout << ".";
					}
				}
				cout << endl;
				if(i == a){
					cout << endl;
				}
			}
		}
	}
	return 0;
}