#include<iostream>
using namespace std;

int change[6]={1,5,10,50,100,500};
int cnt;
int n;

int main(){
	while(cin >> n){
		if(!n)break;
		cnt = 0;
		n = 1000-n;
		for( int i = 5; i >= 0; i-- ){
			while(n>=change[i]){
				n-=change[i];
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}