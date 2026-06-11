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

set<pair<int,int> > tg;
int cnth[300010],cntw[300010];
vector<int> xs,ys;

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	
	int h,w,m;cin>>h>>w>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;cin>>x>>y;x--,y--;
		
		cnth[x]++,cntw[y]++;
		
		tg.insert(mp(x,y));
	}
	
	int maxh=*max_element(cnth,cnth+h);
	int maxw=*max_element(cntw,cntw+w);
	
	for(int i=0;i<h;i++)if(maxh==cnth[i])xs.pb(i);
	for(int j=0;j<w;j++)if(maxw==cntw[j])ys.pb(j);
	
	int ans=maxh+maxw;
	
	for(int i=0;i<xs.size();i++)for(int j=0;j<ys.size();j++)
	{
		if(tg.count(mp(xs[i],ys[j])))continue;
		
		cout<<ans;return 0;
	}
	
	cout<<ans-1;
	
	//printf("Time used = %.12f",(double)(clock())/CLOCKS_PER_SEC);
	return 0;
}

/*  GOD BLESS  */
