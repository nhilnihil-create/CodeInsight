#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1e9+5;
const int N=2e5+5;
const int mod=1e9+7;
vector<int> v[500005];
map<vector<int>,ll> maps;


int main(){
	ios::sync_with_stdio(0);	
	cin.tie(0);
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	while(a>=b){
		b*=2;
		--k;
	}
	while(b>=c){
		c*=2;
		--k;
	}
	cout<<(k<0?"No":"Yes");
	return 0;
}
