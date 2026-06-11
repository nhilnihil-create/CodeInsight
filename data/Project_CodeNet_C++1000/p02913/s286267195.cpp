#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e6+10;
char s[N];
int n,m;
struct _SA{
	#define For(i,a,b) for(int i=a;i<=b;i++)
	#define Rof(i,a,b) for(int i=a;i>=b;i--)
	int sa[N],rk[N],ht[N];
	int h[N],y[N],st[N][22];
	inline void getsa()
	{
		m=150;
	    For(i,0,m)h[i]=0;
	    For(i,1,n)rk[i]=y[i]=0;
	    For(i,1,n)++h[rk[i]=s[i]];
	    For(i,2,m)h[i]+=h[i-1];
	    Rof(i,n,1)sa[h[rk[i]]--]=i;
	    int p=0;
	    for(int i=1;p<=n&&i<=n;i<<=1,m=p){
	        p=0;
	        For(j,n-i+1,n)y[++p]=j;
	        For(j,1,n)if(sa[j]>i)y[++p]=sa[j]-i;
	        For(j,0,m)h[j]=0;
	        For(j,1,n)++h[rk[y[j]]];
	        For(j,1,m)h[j]+=h[j-1];
	        Rof(j,n,1)sa[h[rk[y[j]]]--]=y[j];
	        swap(rk,y);
	        p=1;rk[sa[1]]=1;
	        For(j,2,n)
	            rk[sa[j]]=(y[sa[j-1]]==y[sa[j]] && y[sa[j-1]+i]==y[sa[j]+i]?p:++p);
	    }
	}
	inline void getht(){
		For(i,1,n)rk[sa[i]]=i;int k=0;
		For(i,1,n){
			k=k?k-1:0;int j=sa[rk[i]-1];
			while(s[i+k]==s[j+k]&&i+k<=n&&j+k<=n)k++;
			ht[rk[i]]=k;
		}
		ht[0]=0;
        For(i,1,n)st[i][0]=ht[i];
        For(j,1,21)for(int i=1;i+(1<<j)-1<=n;++i)
           	st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
    inline int lcp(int i,int j){//排名[i-1,j]的最长公共前缀
    	if(i-1>j)return inf;
        int x=log2(j-i+1);
        return min(st[i][x],st[j-(1<<x)+1][x]);
    }
}SA;
priority_queue<int,vector<int>,less<int> >q;
bool check(int x,int k) { 
    while(!q.empty()) q.pop();
    for(int i=1;i<=n+1;i++) {
        if(SA.ht[i]<x) {
            int mi=1e9;
            int gs=0;
            while(!q.empty()) {
                int now=q.top();
                q.pop();
                if(mi>now+x-1) mi=now,gs++;
            }
            if(gs>=k) return 1;
        }
        q.push(SA.sa[i]);
    }
    return 0;
}
int k;
int main()
{
    scanf("%d",&n);
  	k=2;
    scanf("%s",s+1);
    SA.getsa();
    SA.getht();
    //for(int i=1;i<=n;i++) cout<<SA.sa[i]<<endl;
    //for(int i=1;i<=n;i++) cout<<SA.ht[i]<<endl;
    int l=1,r=n/k;
    int ans=0;
    while(l<=r) {
        int mid=(l+r)/2;
        if(check(mid,k)) {
            l=mid+1;
            ans=mid;
        }else {
            r=mid-1;
        }
    }
    printf("%d\n",ans);
}