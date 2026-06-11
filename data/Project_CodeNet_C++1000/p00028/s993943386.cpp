#include<iostream>
using namespace std;
int main(){
	int a[105] = {},b,c=0;
	while(cin>>b){
		a[b]++;
	}
	for (int i = 0; i < 101; i++){
		if (c < a[i]){
			c = a[i];
		}
	}
	for (int i = 0; i < 101; i++){
		if (a[i] == c)cout << i << endl;
	}
	return 0;
}
