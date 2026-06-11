#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
int n,lst,cur,cnt[2];//0:L 1:R
string s;
long long res,MOD=1000000007LL;
int main(){
	#ifdef FILIN
		#ifndef DavidDesktop
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>s;
	lst=0;
	res=1LL;
	cnt[0]=1;
	if(s[0]=='W'||s[n*2-1]=='W'){cout<<0<<endl;return 0;}
	for(int i=1;i<n*2;i++){
		if(s[i]==s[i-1]) cur=1-lst;
		else cur=lst;
		if(cur==0&&i==n*2-1){cout<<0<<endl;return 0;}
		if(cur==1){
			if(cnt[0]<=cnt[1]){cout<<0<<endl;return 0;}
			res=(res*(long long)(cnt[0]-cnt[1]))%MOD;
		}
		cnt[cur]++;
		lst=cur;
	}
	if(cnt[0]-cnt[1]>0)
		res=0;
	for(int i=1;i<=n;i++) res=(res*(long long)(i))%MOD;
	cout<<res<<endl;
	return 0;
}
