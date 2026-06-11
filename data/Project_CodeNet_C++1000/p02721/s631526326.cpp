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
	int n, k, c;
	cin >> n >> k >> c;
	string s;
	cin >> s;
	vector<int> L(k+1);
	vector<int> R(k+1);
	int work = 0, i = 0;
	while (work < k){
		if (s[i] == 'o'){
			L[work] = i;
			work++;
			i += c+1;
		}else{
			i++;
		}
	}
	work = k-1, i = n-1;
	while (work >= 0){
		if (s[i] == 'o'){
			R[work] = i;
			work--;
			i -= c+1;
		}else{
			i--;
		}
	}
	for (int i = 0; i < k; i++){
		if(L[i] == R[i]) cout << L[i]+1 << endl; 
	}
	return 0;
}