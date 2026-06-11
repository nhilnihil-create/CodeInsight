#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	int x;
	cin >> x;
	int answer = 0;
	v1 prime(1, 2);
	if(x == 2){
		answer = 2;
	}else{
		for(int i = 3; i<x; i++){
			int s = prime.size();
			for(int j = 0; j < s; j++){
				if(i%prime[j] == 0) break;
				if(j == s-1) prime.push_back(i);
			}
		}
		bool judge = true;
		int s = prime.size();
		while(judge){
			rep(i, s){
				if(x%prime[i] == 0) break;
				if(i == s-1){
					judge = false;
					answer = x;
				}
			}
			if(judge) x++;
		}
	}
	cout << answer << endl;
}
