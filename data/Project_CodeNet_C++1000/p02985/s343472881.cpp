#include<bits/stdc++.h>
#define ts cout<<"ok"<<endl
#define ll long long
#define hh puts("")
#define pc putchar
#define mo 1000000007
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
using namespace std;
const int N=100005;
int n,m,head[N],cnt,in[N],tot[N],from[N],ans;
struct Edge{
	int v,nx;
}e[N<<1];
inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-1;ch=getchar();}
    while(isdigit(ch)){ret=ret*10+(ch^48);ch=getchar();}
    return ret*ff;
}
void write(int x){if(x<0){x=-x,pc('-');}if(x>9) write(x/10);pc(x%10+48);}
void writeln(int x){write(x),hh;}
void writesp(int x){write(x),pc(' ');}
void add(int x,int y){
	e[++cnt].v=y;
	e[cnt].nx=head[x];
	head[x]=cnt;
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	ans=1;
	queue<int> q;
	q.push(1);in[1]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now==1) ans=m;
		else{
			if(m-tot[from[now]]-1<=0){
				write(0);
				return 0;
			}
			else ans=1ll*ans*(m-tot[from[now]]-1)%mo;
			tot[from[now]]++;//¾àÀëÎª1µÄ 
			tot[now]++;
		}
		for(int i=head[now];i;i=e[i].nx){
			int v=e[i].v;
			if(!in[v]) q.push(v),in[v]=1,from[v]=now;
		}
	}
	write(ans);
	return 0;
}