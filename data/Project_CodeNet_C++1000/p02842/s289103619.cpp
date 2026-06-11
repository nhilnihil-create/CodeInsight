#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int main() {
	int N,ans1,ans2;
	double x;
	cin >> N;
	x = (double)N/1.08;
	ans1 = x;
	ans2 = x+1;
	if(int(ans1 * 1.08) == N){
		cout << ans1;
	}
	else if(int(ans2 * 1.08) == N){
		cout << ans2;
	}
	else{
		cout << ":(";
	}
	return 0;
}