#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {

	int64_t a = 100;
	int64_t X;
	int i =0;
	cin >> X;

	while(true){
		i++;
		//a*=1.01;
		a+=a/100;
		if(a>=X)break;
	}
	cout << i;

	return 0;
}