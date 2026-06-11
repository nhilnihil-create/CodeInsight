#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using ll = long long;
using namespace std;        
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define ar array


void solve(){
		int n;
		cin>>n;
		vector<int> a(n);
		for(auto &x:a){
			cin>>x;
		}
		int x=a[0];
		for(int i=1;i<n;i++){
			x=(int)x^a[i];
		}
		for(int i=0;i<n;i++){
			cout<<int(x^a[i])<<" ";
		}
		cout<<endl;
	
			

}

int main(){
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
//	freopen("input.txt",r,"stdin");
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}



