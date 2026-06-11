#include<bits/stdc++.h>
using namespace std;

const int N = 200005;
typedef long long ll;

int a[N],b[N];
int ans[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,h;
	cin>>h>>n;
	
	ans[0] = 0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	
	for(int i=1;i<=h;i++){
		int mn = 1e9;
		for(int j=0;j<n;j++){
			int nh = max(0,i-a[j]);
			mn = min(mn,b[j] + ans[nh]);
		}
		ans[i] = mn;
	}
	
	cout<<ans[h]<<endl;
	
	return 0;
}