#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string convert(int arg){
	string ret = "";
	int tmp = arg/1000;
	if(tmp > 0){
		if(tmp != 1){
			ret += (char)tmp+'0';
		}
		ret += "m";
	}
	arg -= tmp*1000;
	tmp = arg/100;
	if(tmp > 0){
		if(tmp != 1){
			ret += (char)tmp+'0';
		}
		ret += "c";
	}
	arg -= tmp*100;
	tmp = arg/10;
	if(tmp > 0){
		if(tmp != 1){
			ret += (char)tmp+'0';
		}
		ret += "x";
	}
	arg -= tmp*10;
	if(arg > 0){
		if(arg != 1){
			ret += (char)arg+'0';
		}
		ret += "i";
	}
	return ret;
}

int main(void){
	string str;
	int n;
	cin >> n;
	cin.ignore();
	for(int i=0;i<n;i++){
		int input[2];
		for(int j=0;j<2;j++){
			cin >> str;
			int ii=0,xx=0,cc=0,mm=0;
			for(int k=0;k<str.size();k++){
				if(str[k] == 'i'){
					if(k != 0 && '2' <= str[k-1] && str[k-1] <= '9'){
						ii = str[k-1] - '0';
					}else{
						ii = 1;
					}
				}else if(str[k] == 'x'){
					if(k != 0 && '2' <= str[k-1] && str[k-1] <= '9'){
						xx = str[k-1] - '0';
					}else{
						xx = 1;
					}
				}else if(str[k] == 'c'){
					if(k != 0 && '2' <= str[k-1] && str[k-1] <= '9'){
						cc = str[k-1] - '0';
					}else{
						cc = 1;
					}
				}else if(str[k] == 'm'){
					if(k != 0 && '2' <= str[k-1] && str[k-1] <= '9'){
						mm = str[k-1] - '0';
					}else{
						mm = 1;
					}
				}
			}
			input[j] = ii * 1 + xx * 10 + cc * 100 + mm * 1000;
		}
		cout << convert(input[0] + input[1]) << endl;
	}
}