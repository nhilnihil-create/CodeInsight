
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <tuple>
#include <map>
#include <ctime>
#include <cstdlib>
#include <random>
#include <unistd.h>
using namespace std;

#define int long long

signed main(){
	int sum = 0;
	for(int i = 0; i < 5; i++){
		int a;
		cin >> a;
		sum += a;
		//sum = sum + a;
	}
	cout << 15 - sum << endl;
	return 0;
}