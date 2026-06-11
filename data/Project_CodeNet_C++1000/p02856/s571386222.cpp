#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <numeric>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;

int main(){
	int m;cin >> m;
	ll digit = 0;
	ll res = 0;
	rep(i,m){
		ll c;
		ll d;cin >> d >> c;
		digit += c;
		res += c*d;
	}
	ll ans = digit-1+res/9;
	if(res%9==0) ans--;
	cout << ans << endl;

}
 
 