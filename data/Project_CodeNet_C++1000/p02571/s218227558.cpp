#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define ll long long
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define endl '\n'
#define eps 0.000000001
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int INF=0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;
int d[maxn];
int main(){
	string s,t;cin>>s>>t;
	int lens=s.length(),len=t.length();
	s=" "+s;t=" "+t;
	for(int i=1;i<=lens-len+1;i++){
		for(int j=1;j<=len;j++){
			if(s[j+i-1]!=t[j]) d[i]++;	
		}
	}
	int minn=INF;
	for(int i=1;i<=lens-len+1;i++){
		minn=min(minn,d[i]);
	}
	cout<<minn<<endl;
}
