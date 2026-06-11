#include<bits/stdc++.h>
#define ios std::ios::sync_with_stdio(false)
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for (int i=n;i>=a;i--)
#define ll long long
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define mst(a,n) memset(a,n,sizeof(a))
#define dbg(a, b) cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<endl;
#define debug(a, b, c, d)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define printa(a,l,r) for(int i = l; i <= r; i++){cout << a[i] << " \n"[i==r];}
#define printset(st) for(auto it:st){cout << it << " ";} cout << '\n';
#define printmap(mp) for(auto &it:mp){cout << it.se << " ";} cout << '\n';
//ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
//ll lcm(ll a,ll b){return a*b/gcd(a,b);}
//ll pow_mod(ll x,ll n,ll mod){ll res=1;while(n){if(n&1)res=res*x%mod;x=x*x%mod;n>>=1;}return res;}
//ll fact_pow(ll n,ll p){ll res=0;while(n){n/=p;res+=n;}return res;}
//ll mult(ll a,ll b,ll p){a%=p;b%=p;ll r=0,v=a;while(b){if(b&1){r+=v;if(r>p)r-=p;}v<<=1;if(v>p)v-=p;b>>=1;}return r;}
//freopen("C:/Users/zyj19/Desktop/out.txt","w",stdout);int num = 0;time_t begin,end;double ret;begin=clock();end=clock();ret=double(end-begin)/CLOCKS_PER_SEC;cout<<"runtime: "<<ret<<endl;fclose(stdout);
using namespace std;
template<typename T>void read(T &res){bool flag=false;char ch;while(!isdigit(ch=getchar()))(ch=='-')&&(flag=true);for(res=ch-48;isdigit(ch=getchar());res=(res<<1)+(res<<3)+ch - 48);flag&&(res=-res);}
template<typename T>void Out(T x){if(x<0)putchar('-'),x=-x;if(x>9)Out(x/10);putchar(x%10+'0');}
//struct Edge{int nxt,to;}e[N<<1];int head[N],TOT;void add_edge(int u,int v){e[++TOT].nxt=head[u];e[TOT].to = v;head[u] = TOT;}
//struct node{int k,l,r;bool operator <(const node& A)const{return k < A.k;}};
const int N = 2e5 + 10, MOD = 1e9+7, inf = 0x3f3f3f3f;
//const ll INF = 0x3f3f3f3f3f3f3f3f;

signed main()
{ll a; string b;
	while(cin >> a >> b){
		
	ll sum = 0;
	ll bb = b[0]-'0';
	sum += a * bb;
	bb = b[2]-'0';
	sum += (a * bb)/10;
	float summ = (a*bb)%10/10.0;
	bb = b[3]-'0';
	sum += (a * bb)/100;
	summ += (a*bb)%100/100.0;
	cout << sum + (int)summ<< "\n";
	}
	
    return 0;
}

