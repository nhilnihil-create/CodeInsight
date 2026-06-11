#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
bool ch[3];
int main() {
	for(ll i=0;i<2;i++){
		ll n;
		cin>>n;
		n--;
		ch[n]=true;
	}
	for(ll i=0;i<3;i++){
		if(ch[i]){
			continue;
		}
		cout << i+1;
		return 0;
	}
	// your code goes here
	return 0;
}