#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 200010;

ll n,t,mi,ans=0;;
ll der[2][maxn],vis,cnt[2]; // 0 left ; 1 right
string s;

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	ans=0;
	cin>>s;
	n=s.size();
	if(s[0]=='<') vis=0;
	else{
		vis=1;
		++cnt[0];
		der[0][1]=0;
	}
	
	cnt[vis]=1; ++der[vis][cnt[vis]];
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1]){
			vis=!vis;
			++cnt[vis];
		}
		++der[vis][cnt[vis]];
	}
	
	int m=min(cnt[0],cnt[1]);
	for(int i=1;i<=m;i++){
		ans+=max(der[0][i],der[1][i]);
		ans+=(der[0][i]-1ll)*der[0][i]/2;
		ans+=(der[1][i]-1ll)*der[1][i]/2;
	}
	
	if(cnt[0]>cnt[1]){
		ans+=(der[0][cnt[0]]+1)*der[0][cnt[0]]/2;
	}
	
//	printf("%d %d\n",cnt[0],cnt[1]);
//	for(int i=1;i<=cnt[0];i++){
//		printf("%d ",der[0][i]);
//	}printf("\n");
//	for(int i=1;i<=cnt[1];i++){
//		printf("%d ",der[1][i]);
//	}printf("\n");
	
	printf("%lld\n",ans);
	
	return 0;
}
