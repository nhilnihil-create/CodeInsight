#include <bits/stdc++.h>
using namespace std;
const int mod = 2019;

int modpow(int a,int b){
	int out = 1;
	while(b > 0){
		if(b & 1) out = (out * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return out;
}

int main(){
	string s;
	cin >> s;
	vector <int> hash(2019);
	int n = s.length();
	long long int count = 0;
	int x = 0;
	for(int i = n - 1;i >= 0;--i){
		int num = s[i] - '0';
		x = (modpow(10,n - 1 - i) * num + x) % mod;
		count = count + hash[x];
		if(x == 0) ++count;
		++hash[x];
	}
	cout << count << "\n";
	return 0;
}