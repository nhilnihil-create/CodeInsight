#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=500+5;
const int N=2e5+5;
const ll oo=1e18+5;
const ll mod=998244353;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> a(n);
	bool have_one=0;
	for(int i=0;i<n;++i){
		a[i]=s[i]-'1';
		if(a[i]==1) have_one=1;
	}
	if(!have_one){
		for(int i=0;i<n;++i) a[i]>>=1;
	}
	int ans=0;
	for(int i=0;i<n;++i){
		if(((n-1)&i)!=i) continue;
		ans^=(a[i]&1);
	}
	if(!have_one) ans<<=1;
	cout<<ans;
	return 0;
}
