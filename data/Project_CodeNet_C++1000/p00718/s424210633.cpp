#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

char ctable[4] = {'m', 'c', 'x', 'i'};
int table[4] = {1000, 100, 10, 1};

int rmcxi(){
	int r = 0;
	string s;
	cin>>s;
	int start = 0;
	for(int i = 0; i < s.size();i++){
		for(int j = 0; j < 4; j++){
			if(s[i] == ctable[j]){
				if(start == i){
					r += table[j];
				}else{
					r += atoi(s.substr(start, i-start).c_str()) * table[j];
					#ifdef DEUBG
					cout<<"DEBUG: "<<s.substr(start, i-start)<<endl;
					cout<<"DEBUG r: "<<r<<endl;
					#endif
				}
				start = i+1;
			}
		}
	}
	return r;
}
void wmcxi(int n){
	int num[4];
	for(int i = 0; i < 4; i++){
		num[i] = n/table[i];
		n = n%table[i];
		if(num[i]){
			if(num[i] > 1)cout<<num[i];
			cout<<ctable[i];
		}
	}
	cout<<endl;
}

int main(){
	int N;
	cin>>N;
	while(N--){
		int a, b;
		a = rmcxi();
		b = rmcxi();
		#ifdef DEBUG
		cout<<"a: "<<a<<", b: "<<b<<endl;
		#endif
		wmcxi(a+b);
	}
	return 0;
}