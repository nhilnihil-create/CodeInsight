#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;
 
 
int main(){
	int M, D;
	cin >> M >> D;
	int ans = 0;
	for(int i = 1; i <= M; ++i){
		for(int j = 1; j <= D; ++j) {
			int d1, d2;
			d1 = j % 10;
			d2 = j / 10 % 10;
			if(d1==1||d2==1) continue;
			if(d1*d2==i){
			   	ans++;
			}
		}
	}
	cout << ans << endl;
}
 
 
 
 
 
 