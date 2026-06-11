#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;
typedef long long ll;

const int mod = 1e9+7; 

int main(){
	ios::sync_with_stdio(false);
	int n, k, ans= 0, happy = 0;
	string que;
	cin >> n;
	cin >> k;
	cin >> que;
	for(int i = 1; i < n; ++i){
		if(que[i] == 'L' && que[i-1] == 'L')
			++happy;
	}	
	for(int i = 0; i < n-1; ++i){
		if(que[i] == 'R' && que[i+1] == 'R')
			++happy;
	}
	ans = happy + k * 2;
	cout << (ans > n-1 ? n-1 : ans);
	return 0;
} 