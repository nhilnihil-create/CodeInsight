#include <iostream>

using namespace std;

int main(){
	int h,a;
	cin >> h >> a;
	int ans;
	if(h <= a) ans = 1;
	else ans = (int)(((double)h/(double)a)+0.9); 
	cout << ans << endl;
}