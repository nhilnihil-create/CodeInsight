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
	int n, m;
	string s;
	cin >> n >> m >> s;
	reverse(s.begin(), s.end());
	int now = 0;
	vector<int> vec;
	while(1){
		int temp = now;
		for (int i = m; i >= 1; i--){
			if (now+i <= n && s[now+i] == '0'){
				now += i;
				vec.push_back(i);
				if (now == n){
					for (int j = vec.size()-1; j >= 0; j--){
						cout << vec[j] << " ";
					}
					cout << endl;
					return 0;
				}
				break;
			}
		}
		if (temp == now) break;
	}
	cout << -1 << endl;
	return 0;
}