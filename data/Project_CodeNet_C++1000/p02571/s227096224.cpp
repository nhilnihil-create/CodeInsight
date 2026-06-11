#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int t,n,m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string x,y;
	int ans=1001;
	cin >> x >> y;
	for (int i=0, last=x.length()-y.length(); i<=last; i++){
		int tans=0;
		for (int j=0; j<y.length(); j++){
			if (x[i+j] != y[j]) ++tans;
		}
		ans = min(ans,tans);
	}
	
	cout << ans << endl;
	return 0;
}
