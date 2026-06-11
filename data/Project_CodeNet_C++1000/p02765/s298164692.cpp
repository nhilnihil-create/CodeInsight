#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll k,r;
	cin>>k>>r;
	if(k<10){
		cout << r-100*(k-10);
	}
	else{
		cout <<r;
	}
	// your code goes here
	return 0;
}