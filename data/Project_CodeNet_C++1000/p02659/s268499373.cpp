#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a;
	cin >> a;
	char arr[5];
	scanf("%s", arr);
	int c=0, x=100;
	for(int i=0; i<4; ++i){
		if(arr[i]!='.'){
			c += x * (arr[i]-'0');
			x/=10;
		}
	}
	long long e = (a*c)/100;
	cout << e;
}
