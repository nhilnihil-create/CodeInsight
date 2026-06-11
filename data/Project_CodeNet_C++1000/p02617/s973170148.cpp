#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAXN = 2e5+69;
int n,m;
struct vl{
	int x,y;
};
vector<vl> canh;
signed main(){	
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		canh.push_back({x,y});
	}	
	int ans = 0;
	for(int i=n;i>=1;i--){
		ans+=i*(i+1)/2;
	//	cout<<ans<<endl;
	}
	for(int i=0;i<n-1;i++){
		ans-=(canh[i].x*(n-canh[i].y+1));
	}
	cout<<ans;
}