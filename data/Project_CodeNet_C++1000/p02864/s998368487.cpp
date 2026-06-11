// È¥°É£¡Æ¤¿¨Çð! °ÑAC´ø»ØÀ´£¡
//      ¤Ø¡¡¡¡¡¡¡¡¡¡£¯|
// ¡¡¡¡/£Ü7¡¡¡¡¡¡ ¡Ï£ß/
// ¡¡ /¡¡©¦¡¡¡¡ £¯¡¡£¯								AC		AC		AC		AC
//    ©¦¡¡Z £ß,£¼¡¡£¯¡¡¡¡ /`©c						AC		AC		AC		AC
//    ©¦¡¡¡¡¡¡¡¡¡¡©c¡¡¡¡ /¡¡¡¡¡µ					AC		AC		AC		AC
// ¡¡Y¡¡¡¡¡¡¡¡¡¡`¡¡ /¡¡¡¡/  /						AC		AC		AC		AC
// ¡¡Øé¡ñ¡¡.¡¡¡ñ¡¡¡¡¡´¡¡/¡¡/						AC		AC		AC		AC
// ¡¡()¡¡ ¤Ø¡¡¡¡¡¡¡¡|¡¡£Ü¡´							AC		AC		AC		AC
// ¡¡¡¡>- ._¡¡ ¥£¡¡ ©¦ £¯£¯							AC		AC		AC		AC
// ¡¡ / ¤Ø¡¡¡¡ /¡¡/£¼| £Ü£Ü							AC		AC		AC		AC
// ¡¡ ©c_/¡¡¡¡(_£¯¡¡ ©¦£¯£¯							AC		AC		AC		AC
// ¡¡¡¡ 7¡¡¡¡¡¡¡¡¡¡¡¡¡¡|£¯							AC		AC		AC		AC
// ¡¡¡¡ £¾¨Dr£þ£þ`-¨D£ß/							AC		AC		AC		AC
//**************************************Accepted*****************************************//

#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define Unique(x) x.erase(unique(all(x)),x.end());

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define Pig (OO)

using namespace std;

const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};

const int Days[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};

inline int read()
{
	#define gc getchar
	int ans=0;
	bool f=1;
	char ch=gc();
	
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	
	return f?ans:-ans;
	
	#undef gc
}

typedef long long ll;

int n,k;
ll h[310];
ll DP[310][310][310];

ll DFS(ll lvl,ll cnt,ll idx)
{
	if(DP[lvl][cnt][idx]!=-1)return DP[lvl][cnt][idx];
	
	if(lvl==n)return 0ll;
	
	return DP[lvl][cnt][idx]=min(DFS(lvl+1,cnt,lvl)+max(0ll,h[lvl]-h[idx]),(cnt<k ? DFS(lvl+1,cnt+1,idx) : 1000000000000000000ll));
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	
	for(int i=0;i<310;i++)for(int j=0;j<310;j++)for(int k=0;k<310;k++)DP[i][j][k]=-1;
	
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>h[i];
	
	cout<<DFS(0ll,0ll,n*1ll);
	
	//printf("Time used = %.12f",(double)(clock())/CLOCKS_PER_SEC);
	return 0;
}

/*  GOD BLESS  */
