#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
vector<ll> V;
int pre[maxn];
int main() {
	string a,b;cin>>a>>b;
	int ans=0;
	for(int i=0;i<a.length();i++) {
		ans+=(a[i]!=b[i]);
	}
	cout<<ans<<endl;
    return 0;
}