#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, cnt = 0; cin>>n;
	for(int i = 0; i <n; i++){
		int a, b; cin>>a>>b;
		if(a == b){
			cnt++;
			if(cnt == 3){
				puts("Yes");
				return 0;
			}
		}
		else{
			cnt = 0;
		}
	}
	puts("No");
	return 0;
}