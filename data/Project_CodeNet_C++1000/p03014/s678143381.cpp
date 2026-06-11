//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,w,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	cin >> h >> w;
	vector<string>	s(h);
	vector<vector<ll>>		lh(h+1 , vector<ll>(w+1)),lw(h+1, vector<ll>(w+1));
	for(i=0;i<h;i++) cin >> s[i];

	for(i=0;i<h;i++) for(j=0;j<w;j++) {
		if (s[i][j]=='.') lw[i+1][j+1] = lw[i+1][j] + 1;
	}
	/*
	cout << "lw";
	for(i=0;i<=h;i++) {
		cout << endl;
		for(j=0;j<=w;j++) cout << lw[i][j] << ' ';
	}
	cout << endl;
	*/
	for(i=1;i<=h;i++) for(j=w-1;j>0;j--) {
		if ((lw[i][j]!=0)&&(lw[i][j+1]!=0)) lw[i][j] = lw[i][j+1];
	}
	/*
	cout << "lw";
	for(i=0;i<=h;i++) {
		cout << endl;
		for(j=0;j<=w;j++) cout << lw[i][j] << ' ';
	}
	cout << endl;
	*/
	for(j=0;j<w;j++) for(i=0;i<h;i++) {
		if (s[i][j]=='.') lh[i+1][j+1] = lh[i][j+1] + 1;
	}
	/*
	cout << "lh";
	for(i=0;i<=h;i++) {
		cout << endl;
		for(j=0;j<=w;j++) cout << lh[i][j] << ' ';
	}
	cout << endl;
	*/
	for(j=1;j<=w;j++) for(i=h-1;i>0;i--) {
		if ((lh[i][j]!=0)&&(lh[i+1][j]!=0)) lh[i][j] = lh[i+1][j];
	}
	/*
	cout << "lh";
	for(i=0;i<=h;i++) {
		cout << endl;
		for(j=0;j<=w;j++) cout << lh[i][j] << ' ';
	}
	cout << endl;
	*/
	for(i=1;i<=h;i++) for(j=1;j<=w;j++) {
		a = lw[i][j] + lh[i][j] - 1;
		ans = max(ans , a);
	}
	cout << ans << endl;




	return 0;
}
