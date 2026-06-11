#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e6+69;
const int mod = 1e9+7;
int m,n;
int t;
int x,y,z;
struct vl{
	int x,y;
	bool operator<(vl t)const {
		if(x==t.x)return y<t.y;
		return x<t.x;
	}
};
int a[MAXN];
signed main(){																																																																																						ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s;
	cin>>n>>s;
	for(int i=0;i<s.length();i++){
		cout<<char('A'+(s[i]-'A'+n)%26);
	}
	


	
}  