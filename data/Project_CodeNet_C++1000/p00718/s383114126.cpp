#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

int toInt(string a){
	int ret = 0;
	for(int i=0;a[i];i++){
		int num = 1;
		if(isdigit(a[i])){
			num = a[i++]-'0';
		}
		if(a[i]=='m') ret += num * 1000;
		else if(a[i]=='c') ret += num * 100;
		else if(a[i]=='x') ret += num * 10;
		else if(a[i]=='i') ret += num * 1;
	}
	return ret;
}

string toString(int a){
	string ret;
	char l[5]="ixcm";
	for(int i=0;i<4;i++){
		if(a%10) ret += l[i];
		if(a%10>1) ret += a%10+'0';
		a/=10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int n;
main(){
	int i,j;
	cin >> n;
	while(n--){
		string a,b;
		cin >> a >> b;
		cout << toString(toInt(a) + toInt(b)) << endl;
	}
	return 0;
}