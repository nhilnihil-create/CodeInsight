#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INFL = 1e17+7;
const long long INFI = 1e9+7;
const long long MOD = 1e9+7;
const double EPS = 1e-8;
const double PI=acos(-1);

using namespace std;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int l,r,d;
	cin >> l >> r >> d;
	int ans=0;
	for(int i=l;i<=r;i++){
		if(i%d==0)ans++;
	}
	cout << ans << endl;
	return 0;
}
