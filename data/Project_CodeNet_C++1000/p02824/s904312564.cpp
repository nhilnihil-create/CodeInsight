#include <bits/stdc++.h>
#define int long long
using namespace std;
map<int, int> l, ans;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, x, p;
	cin>>n>>m>>x>>p;
	vector<int>v;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	int ans=0;
	long long cur=0;
	v.push_back(INT_MAX);
	for(int i=0;i<=n;i++){
		if(i==0) cur++;
		else if(v[i]==v[i-1]) cur++;
		else{
			ans+=cur;
			l[v[i-1]]=ans;
			cur=1;
		}
	}
	v.pop_back();
	reverse(v.begin(), v.end());
	int cnt=0, cnt2=1;
	cur=v[p-1];
	for(int i=0;i<n;i++){
		//cout<<v[i]<<endl;
		long long need=(x-(p-1)-l[v[i]])*m, maxi=v[i]+m;
		if(i<p){
			cnt++;
			continue;
		}
		if(v[p-1]>maxi) break;
		if(i>=p){
			//cout<<cnt2<<" "<<maxi<<" "<<cur<<" "<<need<<endl;
			if(cnt2*maxi-cur>=need) cnt++;
			else break;
			cur+=v[i];
			cnt2++;
			//else break;
		}
	}
	cout<<cnt;
}