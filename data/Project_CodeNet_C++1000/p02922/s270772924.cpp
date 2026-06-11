#include<iostream>
 
using namespace std;
 
int main() {
	int a,b;
	cin >> a >> b;
	int ans = 0;
	int sockets = 1;
	while(sockets < b){
        sockets--;
        sockets += a;
        ans++;
	}
	cout << ans << endl;
	return 0;
}