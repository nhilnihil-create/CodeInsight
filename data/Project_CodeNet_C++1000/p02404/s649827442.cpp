#include <iostream>
using namespace std;

int main(){
	int H,W;
	while(cin >> H >> W,H||W){
	for(int i=0;i<W;i++) cout << "#";
	cout << endl;
	H-=2;
	while(H--){
	cout << "#";
	for(int j=1;j<W-1;j++) cout <<".";
	cout << "#"<<endl;
	}
	for(int i=0;i<W;i++) cout << "#";
	cout << endl;
	cout << endl;
	}

	return 0;
}