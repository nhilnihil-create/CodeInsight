/* author   : mpily :-()
title : Competing.cpp
time :Sat May 16 10:36:41 2020

*/
#include<bits/stdc++.h>
using namespace std;
const int64_t mod = 1e9+7;
bool isrot = false;
int64_t res[10000];
void init(){
	for(int i = 0; i < 10000; ++i) res[i] = 0;
}
int main(){
	init();
	int n,p;
	cin >> n >> p;
	string s;
	cin >> s;
	int64_t ans = 0;
	int64_t p10 = 1;
	int md = 0;
	res[0] ++;
	if(p == 2){
		for(int64_t i = 0; i < n; ++i){
			if(s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8'){
				ans+=(i+1);
			}
		}
		cout << ans <<"\n";
		return 0;
	}
	if(p == 5){
		for(int64_t i = 0; i < n; ++i){
			if(s[i] == '0' || s[i] == '5'){
				ans+=(i+1);
			}
		}
		cout << ans <<"\n";
		return 0;
	}
	for(int i = n-1; i >= 0; --i){
		md +=(p10*(s[i]-'0'));
		md%=p;
		ans+=res[md];
		res[md]++;
		p10*=10;
		p10%=p;		
	}
	cout << ans <<"\n";
	return 0;
}