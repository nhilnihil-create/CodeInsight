#include <iostream>
using namespace std;
class DICE{
	public:
	int top,s1,s2,s3,s4,bottom;
	void turnE();
	void turnN();
	void turnS();
	void turnW();
} ;

void DICE::turnE(){
	int tmp=top;
	top=s3;
	s3=bottom;
	bottom=s2;
	s2=tmp;
}

void DICE::turnN(){
	int tmp=top;
	top=s1;
	s1=bottom;
	bottom=s4;
	s4=tmp;
}

void DICE::turnS(){
	int tmp=top;
	top=s4;
	s4=bottom;
	bottom=s1;
	s1=tmp;
}

void DICE::turnW(){
	int tmp=top;
	top=s2;
	s2=bottom;
	bottom=s3;
	s3=tmp;
}

int main(){
	DICE d;
	cin>>d.top>>d.s1>>d.s2>>d.s3>>d.s4>>d.bottom;
	string s;
	cin >> s;
	for(int i=0 ; i<s.length();i++){
		switch(*(s.begin()+i)){
			case 'N':
				d.turnN();
				break;
			case 'E':
				d.turnE();
				break;
			case 'S':
				d.turnS();
				break;
			case 'W':
				d.turnW();
		}
	}
	cout << d.top << endl;
	return 0;
}