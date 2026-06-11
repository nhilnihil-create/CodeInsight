#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main(){
	char c;
	int b[26]={};
	while(cin >> c){
		int a = c-'A';
		if(a>26) a = c-'a';
		b[a]++;
	}
	char d[26];
	for(int i=0;i<26;i++){
		int e = 'a' + i;
		d[i] = e;
	}
	for(int i=0;i<26;i++) cout << d[i] << " : " << b[i] << endl;
}