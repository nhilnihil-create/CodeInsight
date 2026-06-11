#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e6+69;
const int mod = 1e9+7;
const int INF = 1e18;
int m,n;
int t;
int cnt;
int x,y,z;
struct vl{
	int x,y;
	bool operator<(vl t)const {
		if(x==t.x)return y<t.y;
		return x<t.x;
	}
};
int a[MAXN];
int sum[MAXN];
int k;
string s;
map<int,vector<int> >mp;
signed main(){																																																																																						ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	int cur = n;
	a[n]=1;
	while(cur>=0){
		int tmp = cur;
		for(int i=1;i<=m;i++){
			if(cur-i<0){
				cur = tmp;
				goto ss;
			}
			if(s[cur-i]-'0'==0){
				tmp=cur-i;
				a[tmp]=a[cur]+1;	
			}
		}
		//cout<<cur<<' '<<tmp<<endl;
		if(tmp==cur){
			cout<<-1;
			return 0;
		}
		cur = tmp;
	}
	ss:;
	cnt = a[0];
	vector<int>ans;
	for(int i=0;i<=n;i++){
		if(a[i]==cnt){
			ans.push_back(i);
			cnt--;
		}
	}
	for(int i=1;i<ans.size();i++){
		cout<<ans[i]-ans[i-1]<<' ';
	}
}  