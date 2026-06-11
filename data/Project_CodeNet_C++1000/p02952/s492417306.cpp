#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N;
	cin >> N;
	ll num = 0;
	for(ll i = 1; i <= N; i++) {
		if(to_string(i).size() % 2 == 1) {
			num++;
		}
	}
	cout << num << endl;
}
