#include <iostream>
#include <string>
using namespace std;

int main(){
	int h, w;
	for(;;){
		cin >> h >> w;
		if(h == 0) return 0;
		for(int i = 0; i < h; i++){
			string line(w, '#');
			cout << line << endl;
		}
		cout << endl;
	}
}