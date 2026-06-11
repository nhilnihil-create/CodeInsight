#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
 
using namespace std;



int MOD=1000000007;
int main(void){
	int N;
	cin >> N;
	if(N%2==0) cout << N/2-1 << endl;
	else cout << (N+1)/2-1 << endl;
}