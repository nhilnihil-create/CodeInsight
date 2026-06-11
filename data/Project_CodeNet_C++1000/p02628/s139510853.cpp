#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
vector<ll> V;
int pre[maxn];
int main() {
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>pre[i];    
    sort(pre+1,pre+1+n);
	ll sum=0;
	for(int i=1;i<=k;i++) sum+=pre[i];
	cout<<sum<<endl;
    return 0;
}