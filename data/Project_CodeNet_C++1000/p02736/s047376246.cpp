#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define oo 1000000010
const int N = 1000010;
int n;
string s;
char tmpread[N];
int cur[N];

inline int nck(int n,int k){
	if(k > n) return 0;
	if(k == n) return 1;
	return (cur[n] > cur[k] + cur[n - k] ? 0 : 1);
}

int get(string &s){
	int res = 0;
	for(int i = 0 ;i < (int)s.size();i++){
		if(s[i] == '0') continue;
		res ^= nck((int)s.size() - 1 , i);
	}
	return res;
}



int main(){
	for(int i = 2;i < N;i *= 2){
		for(int j = i ;j < N;j += i) cur[j]++;
	}
	for(int i = 2;i < N;i++) cur[i] += cur[i - 1];
	scanf("%d",&n);
	scanf("%s",tmpread);
	s = (string)tmpread;
	bool one = false, two = false;
	for(int i = 0 ;i < n;i++){
		s[i]--;
		if(s[i] == '1') one = true;
		if(s[i] == '2') two = true;
	}
	if(one && two){
		for(int i = 0 ;i < n;i++) if(s[i] == '2') s[i] = '0';
		two = false;
	}
	if(one){
		printf("%d\n",get(s));
	}
	else{
		printf("%d\n",get(s) * 2);
	}
	return 0;
}