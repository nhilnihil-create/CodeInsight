#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e7+5;
vector<ll> V;
ll cnt[maxn];
int main() {
    for(int i=1;i<maxn;i++) 
    	for(int j=i;j<maxn;j+=i) cnt[j]++;
    int n;ll ans=0;cin>>n;
	for(int i=1;i<=n;i++) ans+=cnt[i]*i;
		cout<<ans<<endl;
    return 0;
}