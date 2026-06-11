#include <bits/stdc++.h>
using namespace std;

int main(){
	int a;
	cin >> a;
	for(int i=0; ;i++){
		if(i*1000<a) continue;
		else if(i*1000==a){
			cout << 0;
			return 0;
		}
		else{
			cout << i*1000-a;
			return 0;
		}
	}
}