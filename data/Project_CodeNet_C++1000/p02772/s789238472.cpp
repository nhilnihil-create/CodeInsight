#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
string ans="APPROVED";
int n;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		if(a%2==0&&a%3&&a%5) ans="DENIED";
	}
	cout<<ans;
	re 0;
}