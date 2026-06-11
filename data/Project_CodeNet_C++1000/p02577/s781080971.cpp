#include <bits/stdc++.h>
using namespace std;

#define ll long long

string N;

int main(){
	cin >> N;
	int sm = 0;
	for (auto n : N){
		sm += (n - '0')%9;
		sm %= 9;
	}
	cout << (sm == 0 ? "Yes" : "No") << "\n";
}