#include <iostream>

using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	
	int ans = a<(b*2)?0:a-(b*2);
	cout << ans << endl;
	
}