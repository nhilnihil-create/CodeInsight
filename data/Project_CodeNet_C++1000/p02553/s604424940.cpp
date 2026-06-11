#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1000000000+5;
const int N=1e6+5;
const ll oo=1e18+5;
const ll mod=1e9+7;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	if((a>0&&d<0)||(b<0&&c>0)){
		cout<<max(a*d,c*b);
	}
	else{
		cout<<max(a*c,b*d);
	}
	return 0;
}
