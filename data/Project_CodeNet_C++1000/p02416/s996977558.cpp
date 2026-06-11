#include <iostream>
using namespace std;

int sum(char *buf){
	char *p = buf;
	int sum = 0;
	while(*p != 0){
		if('0' <= *p && *p <= '9'){
			sum += *p - '0';
		}
		p++;
	}
	return sum;
}

int main(int argc, char *argv[]){
	char buf[1000+2];
	while(1){
		cin.getline(buf,sizeof(buf));
		if (buf[0] == '0')break;
		cout << sum(buf) << endl;
	}
}