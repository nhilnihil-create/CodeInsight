#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0);
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	int cnt=0;
	while(b<=a){
		b*=2;
		cnt++;
	}
	while(c<=b){
		c*=2;
		cnt++;
	}
	if(cnt>k) cout<<"No";
	else cout<<"Yes";
	re 0;
}
