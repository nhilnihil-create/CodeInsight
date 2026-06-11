#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int N;

void stringEq(vector<char> a, char mx){
	if(a.size() == N){
		rep(i, N){
			cout << a.at(i);
		}
		cout << endl;
		return;
	}
	int t = mx-97+2;
	rep(i, t){
		char b = 97 + i;
		vector<char> c = a;
		c.push_back(b);
		stringEq(c, max(b, mx));
	}
}

int main(){
	cin >> N;
	vector<char> a(0);
	char c = 'a';
	a.push_back(c);
	stringEq(a, c);
}
