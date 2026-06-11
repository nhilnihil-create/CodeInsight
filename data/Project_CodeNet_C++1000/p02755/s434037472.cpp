#include <iostream>

using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	int ans = -1;
	for(int i = 0; i < 1010; i++){
		if((int)(i * 0.08) == a && (int)(i * 0.1) == b) {
			ans = i;
			break;
		}
	}
	
	cout << ans << endl;
}