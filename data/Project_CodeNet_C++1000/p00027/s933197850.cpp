#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int m,d;
	int day[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int y[12];
	string s[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	y[0] = 3;
	for(int i=1;i<12;i++) y[i] = (y[i-1]+day[i-1])%7;
	while(1){
		cin >> m >> d;
		if(m==0) break;
		int t = (y[m-1]+d-1)%7;
		cout << s[t] << endl;
	}
}