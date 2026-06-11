#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
	bool ch[101000];
int main() {
	ll n;
	cin>>n;
	ch[0]=true;
	for(ll i=0;i<=100000;i++){
		if(ch[i]){
			for(ll j=0;j<=5;j++){
				ch[i+100+j]=true;
			}
		}
	}
	if(ch[n]){
		cout <<1;
	}
	else{
		cout << 0;
	}
	// your code goes here
	return 0;
}