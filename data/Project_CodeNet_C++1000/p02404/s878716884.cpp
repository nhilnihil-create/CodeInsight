#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int h,w;
	cin >> h >> w;
	while(h!=0 || w!=0){

		for(int j=0;j<w;j++){
			cout << "#";
		}
		cout << endl;

		for(int i=1;i<h-1;i++){
			cout << "#";
			for(int j=1;j<w-1;j++){
				cout << ".";
			}
			cout << "#" << endl;
		}

		for(int j=0;j<w;j++){
			cout << "#";
		}
		cout << endl;

		cout << endl;
		
		cin >> h >> w;
	}
}