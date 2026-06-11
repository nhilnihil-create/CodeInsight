#include <iostream>
#include <time.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	int num = 1;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] != num){
			ans++;
		}else num++;
	}
	if(num == 1) ans = -1;
	
	cout << ans << endl;
}