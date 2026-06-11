#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n, a, b; cin >> n >> a >> b;
	string ans = "NG";
	for (int i=0;i<100000;i++)
		if ((a<=n*i)&&(n*i)<=b) { ans = "OK"; }
	cout << ans << endl;
}