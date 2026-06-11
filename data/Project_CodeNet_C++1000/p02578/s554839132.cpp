#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n = 0;
	cin >> n;
	int i = 0; int j = 0;
	unsigned long long res = 0;
	while (n--){
		cin >> i;
		if (i < j){ 
			res += j - i;
			i = j;
		
		}
		j = i;
	}
	cout << res;

	//system("pause");
	return 0;
}
