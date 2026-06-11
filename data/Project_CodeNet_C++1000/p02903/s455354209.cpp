#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll h,w,a,b;
	cin>>h>>w>>a>>b;
	bool ch=true;
	for(ll i=0;i<h;i++){
		if(i==b){
			ch=false;
		}
		for(ll j=0;j<w;j++){
			if(j<a){
				cout << abs(ch-1);
			}
			else{
				cout << abs(1-abs(ch-1));
			}
		}
		cout <<endl;
	}
	// your code goes here
	return 0;
}