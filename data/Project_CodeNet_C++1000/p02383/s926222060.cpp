#include <iostream>
#include <string>
using namespace std;

class dice{
	int d[6];
	int t;
public:
	int setdice();
	int showresult();
	int mvdice(string op);
};

int dice :: setdice(){
	for(int i = 0; i < 6; i++){
		cin >> d[i];
	}
	return 0;
}

int dice :: showresult(){
	cout << d[0] << endl;
	return 0;
}

int dice :: mvdice(string op){
	for(int i = 0; i < op.length(); i++){
		switch(op[i]){
			case 'N':
				t = d[0];
				d[0] = d[1];
				d[1] = d[5];
				d[5] = d[4];
				d[4] = t;
				break;
			case 'S':
				t = d[0];
				d[0] = d[4];
				d[4] = d[5];
				d[5] = d[1];
				d[1] = t;
				break;
			case 'W':
				t = d[0];
				d[0] = d[2];
				d[2] = d[5];
				d[5] = d[3];
				d[3] = t;
				break;
			case 'E':
				t = d[0];
				d[0] = d[3];
				d[3] = d[5];
				d[5] = d[2];
				d[2] = t;
				break;
		}
	}
	return 0;
}

int main(){
	dice x;
	string op;
	x.setdice();
	cin >> op;
	x.mvdice(op);
	x.showresult();
	return 0;
}