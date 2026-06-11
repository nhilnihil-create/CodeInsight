#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
#define endl '\n'
#define F first
#define S second
typedef pair<int,int> pii;
typedef long long ll;


void A(){
	/**ios_base::sync_with_stdio(0); cin.tie(0);
	int x, y, z;
	cin>>x>>y>>z;
	cout<<min({x+y, x+z, y+z})<<endl;*/
}
int main(){
	int n; cin>>n;
	int arr[n]; cin>>arr[0];
	for(int i=1; i<n; i++){
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	int ans = 1e6;
	for(int i=0; i<n-1; i++){
		ans=min(ans, abs(arr[i] - (arr[n-1]-arr[i])));
	}
	cout<<ans<<endl;
}
