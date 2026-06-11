#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	long long n,x;
	cin >> n;
	x = n;
	string name;
	while (n > 0) {
		name += 'a' + (n-1) % 26;
		//cout <<"余り"<< (n-1)% 26 << endl;
		n = (n-1)/ 26;
		//cout <<"n="<< n << endl;
	}
	reverse(name.begin(), name.end());
	cout << name << endl;
	return 0;
}