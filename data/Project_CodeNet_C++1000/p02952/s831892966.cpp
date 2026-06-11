#include <iostream>
#include <stdlib.h>
#include <string>
#define rep(i, n) for(int i = 1; i < n; i++)

using namespace std;

int main(){
	int n;
	cin >> n;
	
	int ans = 0;
	
	rep(i, n+1){
		string num = to_string(i);
		if(num.size() % 2 != 0) ans++;
	}
	cout << ans << endl;
	
}