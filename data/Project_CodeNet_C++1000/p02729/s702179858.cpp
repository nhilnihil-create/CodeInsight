#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	
	//偶数＋偶数の数
	int ev = n*(n-1) / 2;
	
	//奇数＋奇数の数
	int od = m*(m-1) / 2;
	
	int ans = ev + od;
	cout << ans << endl;
	
}