#include<iostream>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int main(){
	int a;
	rep(i,5){
		cin >>a;
		if(a==0){
			cout << i+1;
		}
	}
	return 0;
}