#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()
#define init(c) memset(c,0,sizeof c)
#define S second
#define F first
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int N=20000005;
int n,k,x,t,a,b,m;
string s;
vi v;

void solve(){
	cin >>x;
	for(int i =1;i<=x;i++){
		if((360*i)%x == 0){
			cout << (360*i)/x;
			return;
		} 
	}
}

int main(){

	int t= 1;
	while(t--){
		solve();
	}
	
	return 0;
}