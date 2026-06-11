#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll cnt1=n/100;
 	ll cnt2=n%100;
 	if(cnt1*5>=cnt2){
 		cout << 1;
 	}
 	else{
 		cout << 0;
 	}
	// your code goes here
	return 0;
}