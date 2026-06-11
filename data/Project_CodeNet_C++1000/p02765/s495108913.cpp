#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll n,r;
	cin>>n>>r;
	if(n>=10){
		cout <<r;
	}
	else{
		cout << r+100*(10-n);
	}
	// your code goes here
	return 0;
}