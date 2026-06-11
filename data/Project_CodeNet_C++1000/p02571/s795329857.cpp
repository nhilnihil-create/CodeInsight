/*@author Vipen Loka*/
#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define deb(x) cout << #x << ':' << x << '\n';

using namespace std;

void solve(){
	int i,j;
	int ans=INT_MAX;

	string a,b;cin >>a >> b;

	int n=a.size(),m=b.size();

	for (int i = 0; i < n-m+1; ++i)
	{
		int cnt=0;
		for (int j = 0; j < m; ++j)
		{
			if(a[i+j]!=b[j])cnt++;
		}
		ans=min(cnt,ans);
	}

	printf("%d\n",ans);

}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	int T=1;
	// cin >> T;
	while (T--){
		solve();
	}
}
