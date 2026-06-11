#include<iostream>
using namespace std;

int main(){
	while(1){
		int n,r,p,c;
		cin >> n >> r;
		if(n == 0 && r ==0)break;
		int s[n + 1];
		for(int i = 1; i <= n;++i){
		s[i] = i;
		}
		for(int j = 0; j < r;++j){
			cin >> p >> c;
			if(p == 1)continue;
			for(int k = 0;k < c;++k){
				s[0] = s[n + 2 - p - c];
				for(int l = 0;l < p + c - 2;++l){
					s[n + 2 - p - c + l] = s[n + 3 - p - c + l];
					}
				s[n] = s[0];
			}
		}
		  cout << s[n] << endl;

	}
	return 0;
}