#include<iostream>
#include<algorithm>

using namespace std;

bool notprime[1080000];

int main(){
	notprime[1] = true;
	notprime[0] = true;
	for(int i = 2;i * i < 1080000;i++){
		if(notprime[i])continue;
		for(int j = i * i;j < 1080000;j += i){
			notprime[j] = true;
		}
	}
	int a, d, n;
	while(cin >> a >> d >> n, a | d | n){
		for(int i = a;i < 1080000;i += d){
			if(!notprime[i])n--;
			if(n == 0){
				cout << i << endl;
				break;
			}
		}
	} 
	return 0;
}