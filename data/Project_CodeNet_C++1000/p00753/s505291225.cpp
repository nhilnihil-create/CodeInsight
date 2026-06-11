#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n;
	while(1){
		cin >> n;
		if(n == 0) break;
		int s[n];
		int i, j, count = 0;
		bool sosu = true;
		for(i = 0;i < n;i++){
			s[i] = n + 1 + i;
			//cout << "s[i] = " << s[i] << endl;
		}

		for(i = 0;i < n;i++){
			sosu = true;
			for(j = 2;j*j < s[i]+1;j++){
				//cout << "s[i] = " << s[i] << " j*j = " << j*j << endl;
				if(s[i] % j == 0){
					sosu = false;
					break;
				}
			}
			if(sosu){
				count++;
			}
		}

		cout << count << endl;
	}

	return 0;
}