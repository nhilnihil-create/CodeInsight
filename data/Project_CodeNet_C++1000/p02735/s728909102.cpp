#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
#define _GLIBCXX_DEBUG
#define acc_io cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(ll i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define DBG(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl
const ll MOD = 1000000007;
const double PI = acos(-1);  
//name[i]   -> vi  name
//name[i][j]-> vi name[i]
//or-> ||
//map<int,int>mp

//ll n;
//ll ans;
//int ans;
//string s;


signed main(){
	acc_io;
	int H,W;
	string s[100];
	cin>>H>>W;
	rep(i,0,H){
		cin>>s[i];
	}
	int cnt[H][W];
	rep(i,0,W){
		rep(j,0,H){
			if(i+j==0){
				if(s[0][0]=='#')	cnt[0][0]=1;
				else				cnt[0][0]=0;
			}
			else{
				cnt[j][i]=1e9;
				if(i>0){
					if(s[j][i]=='#'&&s[j][i-1]=='.'){
						cnt[j][i]=min(cnt[j][i],cnt[j][i-1]+1);
					}
					else{
						cnt[j][i]=min(cnt[j][i],cnt[j][i-1]);
					}
				}
				if(j>0){
					if(s[j][i]=='#'&&s[j-1][i]=='.'){
						cnt[j][i]=min(cnt[j][i],cnt[j-1][i]+1);
					}
					else{
						cnt[j][i]=min(cnt[j][i],cnt[j-1][i]);
					}
				}
			}
		}
	}
	cout<<cnt[H-1][W-1]<<endl;
	return 0;
}
