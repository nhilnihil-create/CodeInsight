#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	while(1){
		int s = 0;
		cin>>N;
		if(N == 0) break;
		for(int i = N + 1; i <= N * 2; i++){
			int k = 0;
			for(int j = 2; j * j <= i; j++){
					
				if(i % j == 0){
					k = 1;
					break;
				}
			}
			if(k == 0) s++;
		}
		cout<<s<<endl;
		
	}
	return 0;
}

