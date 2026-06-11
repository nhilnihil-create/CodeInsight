#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define EPS 1e-7

int main(){
	int n;
	while(cin >> n && n){
		int sqrtn = (int)(sqrt(2*n) + EPS);
		int ret=0;
		bool isprimelow[sqrtn+1];
		bool isprimehigh[n];
		
		memset(isprimelow, true, sizeof(isprimelow));
		memset(isprimehigh, true, sizeof(isprimehigh));
		
		isprimelow[0] = false;
		isprimelow[1] = false;
		for(int i=2;i<=sqrtn;i++){
			if(isprimelow[i]){
				for(int j=2;i*j<=sqrtn;j++){
					isprimelow[i*j] = false;
				}
				for(int j=n/i;i*j <= 2*n;j++){
					if(n < i*j && i*j <= 2*n){
						isprimehigh[i*j-n-1] = false;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			if(isprimehigh[i]) ret++;
		}
		cout << ret << endl;
	}
}