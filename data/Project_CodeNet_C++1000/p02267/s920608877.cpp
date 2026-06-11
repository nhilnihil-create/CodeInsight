#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#define rep(i,o,u) for(int i = o;i < u; i++)
using namespace std;
int a[10000+1];
int search(int k,int n){
	rep(i,0,n){
		if(a[i] == k){
			return 1;
		}
	}
	return 0;
}
int main(){
	int n;
	cin >> n;
	rep(i,0,n) cin >> a[i];
	int m;
	cin >> m;
	int k;
	int ans = 0;
	while(m--){
		cin >> k;
		if(search(k,n)) ans++;
	}
	cout << ans << endl;
	return 0;
}