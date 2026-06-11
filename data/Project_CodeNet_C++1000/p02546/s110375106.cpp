#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

#define llong long long
#define rep(i,l,n) for(llong (i)=(l);(i)<(n);(i++))
#define _min(a,b) ((a)<(b)?(a):(b))
#define _max(a,b) ((a)>(b)?(a):(b))
#define _abs(a) ((a)>0?(a):(-(a)))

using namespace std;

int main(){
	string s,t;
	cin >> s;
	int n = s.size();
	if( s[n-1]=='s' ){
		t = "es";
	}else{
		t = "s";
	}
	cout << s+t;
}
