#include <iostream>

using namespace std;
int k, resp;

int mdc(int a, int b){
	return (b == 0)? a: mdc(b, a%b);
}

int main(){
	cin >> k;
	resp = 0;
	
	for(int i = 1; i <= k; i ++){
		for(int j = 1; j <= k; j ++){
			for(int w = 1; w <= k; w ++){
				resp += mdc(mdc(i, j), w);
		
			}
		}
	}
	cout << resp;
	return 0;
}