#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define MOD 1000000007
 #define PI 3.141592653
using namespace std;

int A[101];

void solve(){
	int n,k; cin>>n>>k;
	string s; cin>>s;
	int m=1;
	int ans=0;

	for(int i=0; i<n-1; i++){
		if(s[i] == s[i+1]){
			ans++;
		}
		else m++;
	}
	int q = (m/2 - 1 + m%2);
	ans += min(q,k)*2;
	if(k>q){
		ans += 1-m%2;
	}
	cout<<ans;


}


int main()
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	int t =1; //cin>>t;
	for(int i=1; i<=t; i++){
		solve();
		cout<<"\n";
	}
	return 0;

}
