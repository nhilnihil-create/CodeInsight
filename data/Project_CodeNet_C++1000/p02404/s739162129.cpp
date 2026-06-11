#include <iostream>
using namespace std;

void printa(int w) {
	while(w--) {
		cout<<"#";
	}
	cout<<endl;
}

void printb(int w) {
	w-=2;
	cout<<"#";
	while(w--) {
		cout<<".";
	}
	cout<<"#"<<endl;
}

int main() {
	int h,w;
	while(cin>>h>>w,h) {
		h-=2;
		printa(w);
		while(h--) {
			printb(w);
		}
		printa(w);
		cout<<endl;
	}
	return 0;
}