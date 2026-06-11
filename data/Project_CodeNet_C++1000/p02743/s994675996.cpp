#include<bits/stdc++.h>
#define pb push_back
#define inf 0x3f3f3f3f
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define mem(a,val) memset(a,val,sizeof(a))
#define mkp make_pair
#define all(n) (n).begin(),(n).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	ll  x = c-a-b;

	if( x > 0  &&  x * x > 4LL * a * b )
		cout<<"Yes\n";
	else cout<<"No\n";
}