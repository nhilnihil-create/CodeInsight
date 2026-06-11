#include <iostream>
using namespace std;

void writeLine(int W);

int main(){
	int H, W = 0;
	bool flag = true;

	while(flag == true){
		cin>>H>>W;

		if(H == 0 && W == 0) break;

		writeLine(W);

		for(int i = 0; i < H -2; i ++){
			cout<<"#";
			for (int j = 0;j < W -2; j++){
				cout<<".";
			}
			cout<<"#"<<endl;
		}

		writeLine(W);
		cout<<endl;
	}
}

void writeLine(int W){
	for(int i = 0; i < W; i++){
			cout<<"#";
		}
		cout<<endl;
}