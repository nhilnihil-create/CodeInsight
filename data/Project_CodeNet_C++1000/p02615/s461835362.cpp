#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+7;
int a[N];
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	queue<pair<int,int> > q;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>() );
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(q.empty()) q.push(make_pair(a[i],a[i]));
		else{
			int x1 = q.front().first;
			int x2 = q.front().second;
			ans += min(x1,x2);
			q.pop();
			q.push(make_pair(x1,a[i]));
			q.push(make_pair(a[i],x2));
		}
	}
	cout<<ans<<endl;
}