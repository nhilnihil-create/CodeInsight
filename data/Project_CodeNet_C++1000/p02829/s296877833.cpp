#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll ch[3];
int main() {
	for(ll i=0;i<2;i++){
		ll now;
		cin>>now;
		now--;
		ch[now]=true;
	}
	for(ll i=0;i<3;i++){
		if(ch[i]==false){
			cout << i+1;
		}
	}
	// your code goes here
	return 0;
}