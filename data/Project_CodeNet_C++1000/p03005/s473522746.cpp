#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
 
using namespace std;


int MOD=1000000007;


int main() {
	int N,K;
	cin >> N >> K; 
	if(K==1) cout << 0 << endl;
	else cout << N-K << endl;
}
