#include<bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair< int, int > ii;
typedef vector< ii > vii;

void solve(){
	int n; cin>>n;
	for(double i = 0; i<=n; i++){
		double ans = i * 1.08;
		//cout<<ans<<endl;
		if((int)ans == n){
			cout<<i<<endl;
			return;
		}
	}
	cout<<":("<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//int t; cin>>t;
	//cout<<fixed<<setprecision(3);
	//while(cin>>n, n){
		solve();
	//}
	return 0;
}

