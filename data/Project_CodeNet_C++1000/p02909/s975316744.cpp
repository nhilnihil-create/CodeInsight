#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	string a,b,c;
	a="Sunny";
	b="Cloudy";
	c="Rainy";
	cin>>s;
	if(s==a){
		cout << b;
	}
	else if(s==b){
		cout <<c;
	}
	else{
		cout <<a;
	}
	// your code goes here
	return 0;
}