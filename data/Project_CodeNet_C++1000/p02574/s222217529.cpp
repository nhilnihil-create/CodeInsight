#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1000000000+5;
const int N=2e5+5;
const ll oo=1e18+5;
const ll mod=1e9+7;

int root[1000005];
int cntt[1000005];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int& x:a) cin>>x,++cntt[x];
	bool pairwise=1;
	for(int i=2;i<1000005;++i){
		int cnt=0;
		for(int j=i;j<1000005;j+=i){
			cnt+=cntt[j];
		}
		if(cnt>1) pairwise=0;
	}
	if(pairwise) return cout<<"pairwise coprime",0;
	int g=0;
	for(int i=0;i<n;++i) g=__gcd(g,a[i]);
	if(g==1) return cout<<"setwise coprime",0;
	cout<<"not coprime"; 
	return 0;
}
