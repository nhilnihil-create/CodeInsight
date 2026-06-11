#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;


int main(){
	ll n, k;
	cin >> n >> k;
	if ((n-1)*(n-2)/2 >= k){
		int temp = (n-1)*(n-2)/2;
		cout << n-1 + temp - k << endl;
		for (int i = 1; i < n; i++){
			cout << n << " " << i << endl;
		}
		int coun = 0;
		if (temp - k == 0) return 0;
		for (int i = 1; i < n; i++){
			for (int j = i+1; j < n; j++){
				cout << i << " " << j << endl;
				coun++;
				if (coun == temp - k){
					return 0;
				}
			}
		}
	}else{
		cout << -1 << endl;
	}
	return 0;
}
