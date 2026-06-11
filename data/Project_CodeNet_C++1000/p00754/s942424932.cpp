#include <iostream>
using namespace std;

const int MAX_LENGTH = 1 << 10;

bool isYes(char input[]);

int main()
{
	char Input[MAX_LENGTH];
	int i=0;
	while(true){
		cin.getline(Input, sizeof(Input));
		if(Input[0] == '.') break;
		if(isYes(Input)){
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}

bool isYes(char Input[])
{
	enum __FLAG{NONE, PARE, BLAC};
	int prep[MAX_LENGTH], prepnum=0, p=NONE;
	for(int i=0; Input[i]!='.'; i++){
		if(Input[i] == '('){
			if(p != NONE){
				prep[prepnum] = p;
				prepnum++;
			}
			p=PARE;
		} else if(Input[i] == '['){
			if(p != NONE){
				prep[prepnum] = p;
				prepnum++;
			}
			p=BLAC;
		} else if(Input[i] == ')'){
			if(p!=PARE){
				return false;
			} else {
				if(prepnum==0) p=NONE;
				else {
					p = prep[prepnum-1];
					prepnum--;
				}
			}
		} else if(Input[i] == ']'){
			if(p!=BLAC){
				return false;
			} else {
				if(prepnum==0) p=NONE;
				else {
					p = prep[prepnum-1];
					prepnum--;
				}
			}
		}
	}
	return p==NONE;
}