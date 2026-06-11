#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;
lli k;

lli calc(string x){
	lli ret = 0;
	lli n = x.size();
	for(int i = 0, j = 0; i < n; i = j){
		while(j < n && x[i] == x[j]) j++;
		ret += (j-i)/2;
	}
	return ret;
}

int main(void){
	cin >> s >> k;
	lli n = s.size();
	if(s.find_first_not_of(s[0]) == string::npos){
		cout << n*k/2 << endl;
		return 0;
	}
	lli d1 = calc(s);
	lli d2 = calc(s+s);
	lli a = d1;
	lli d = (d2-d1);
	cout << a + (k-1)*d << endl;
	return 0;
}
