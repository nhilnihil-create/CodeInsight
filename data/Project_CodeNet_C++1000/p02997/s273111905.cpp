#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


int main(){
	int n, k;
	cin >> n >> k;
	
	if (k <= (n-1)*(n-2)/2){
		int temp = (n-1)*(n-2)/2 - k;
		cout << n-1 + temp << endl;
		for (int i = 2; i <= n; i++){
			cout << 1 << " " << i << endl;
 		}
 		if (temp > 0){
 			 int coun = 0;
 			for (int i = 2; i <= n-1; i++){
 				for (int j = i + 1; j <= n; j++){
 					cout << i << " " << j << endl;
 					coun++;
 					if (coun == temp) return 0;
 				}
 			}
 		}
 		return 0;
	}
	cout << -1 << endl;
	return 0;
}
