#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mod = 1e9+7;
const ll inf = 1e18;
const double pi = 3.1415926535897932384626;

void solve(){
	//code
	int a,b;
	cin>>a>>b;
	if(a>9 || b>9) cout<<-1;
	else cout<<a*b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
 	return 0;
}
