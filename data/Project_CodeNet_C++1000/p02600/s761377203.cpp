#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1e9+5;
const int N=2e5+5;
const int mod=1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x;
	cin>>x;
	int init=400;
	int now=8;
	while(1){
		if(x>=init&&x<=init+199){
			return cout<<now,0;
		}
		--now;
		init+=200;
	}
	return 0;
}
