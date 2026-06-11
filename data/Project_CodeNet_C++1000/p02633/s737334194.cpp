#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a;
	cin >> a;

	// for(int a = 1; a <= 179; a++ ){
	// cout << "a= " << a << " ";
	if(360 % a == 0){
		cout << 360 / a;
		cout << endl;
	}else{
		int x = 360;
		int ans = 0;
		while(x != 0){
			if(x > 0) x -= a;
			else{
				x += 360;
				x -= a;
			}
			ans++;
		}
		cout << ans;
	}
	// }
	return 0;
}
