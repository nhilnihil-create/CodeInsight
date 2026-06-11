#include<iostream>
using namespace std;

const int MAX_N = 123456 * 2 + 1;

int main(){
	bool list[MAX_N];
	for(int i = 0;i < MAX_N;i++) list[i] = true;
	list[0] = list[1] = false;
	
	for(int i = 0;;i++){
		if(list[i]){
			for(int j = i * 2;j < MAX_N;j += i) list[j] = false;
			if(i * i > MAX_N) break;
		}
	}
	
	while(1){
		int n;
		cin >> n;
		if(n == 0) break;
		int ans = 0;
		for(int i = n + 1;i <= n * 2;i++){
			if(list[i]) ans++;
		}
		cout << ans << endl;
	}
	
	return 0;
}