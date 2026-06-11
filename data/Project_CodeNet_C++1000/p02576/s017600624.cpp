#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N, X, T;

int main(){
	cin >> N >> X >> T;
	cout << T * (N / X + (N % X != 0) ) << "\n";
}