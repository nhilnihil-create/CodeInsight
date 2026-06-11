#include <bits/stdc++.h>
#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)
#define _all(arg) begin(arg),end(arg)
#define in(a,b,c) (b<=a&&a<=c)

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0; }
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0; }

using namespace std;

int decode(string e) {
	int res = 0;
	rep(i,e.size()) {
		switch(e[i]) {
			case 'm':
				if(i && in(e[i-1],'0','9')) res+=(e[i-1]-'0')*1000;
				else res += 1000;
				continue;
			case 'c':
				if(i && in(e[i-1],'0','9')) res+=(e[i-1]-'0')*100;
				else res += 100;
				continue;
			case 'x':
				if(i && in(e[i-1],'0','9')) res+=(e[i-1]-'0')*10;
				else res += 10;
				continue;
			case 'i':
				if(i && in(e[i-1],'0','9')) res+=(e[i-1]-'0')*1;
				else res += 1;
				continue;
		}
	}
	return res;
}

string encode(int n) {
	string res = "";
	if(n/1000) {
		if((n/1000)-1) {
			res += (n/1000)+'0';
		}
		res += "m";
		n%=1000;
	}
	if(n/100) {
		if((n/100)-1) {
			res += (n/100)+'0';
		}
		res += "c";
		n%=100;
	}
	if(n/10) {
		if((n/10)-1) {
			res += (n/10)+'0';
		}
		res += "x";
		n%=10;
	}
	if(n/1) {
		if(n-1) {
			res += n+'0';
		}
		res += "i";
	}
	return res;
}

int main(void){
	int n; cin >> n;
	while(n--) {
		string in1, in2; cin >> in1 >> in2;
		cout << encode(decode(in1)+decode(in2)) << endl;
	}
        
	return 0;
}