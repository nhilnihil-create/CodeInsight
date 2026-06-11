#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include<stack>
#include<string>
#include<algorithm> 
#include <set>
#include<list>
#include <bit>
#include <bitset>
#include <cstdint>
#include <initializer_list>
using namespace std;
int main() {
	long long int N, ans=0,max_val=10000000; cin >> N;

	vector<long long int >data(N);
	for (int i = 0; i < N; i++)cin >> data[i];
	for (int i = 0; i < N; i++) {
		if (max_val >= data[i]) {
			max_val = data[i];
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}