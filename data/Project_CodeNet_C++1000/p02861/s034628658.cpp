
// Problem : C - Average Length
// Contest : AtCoder - AtCoder Beginner Contest 145
// URL : https://atcoder.jp/contests/abc145/tasks/abc145_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include<set>
#include<map>
#include<bitset>
#define rep(i,a,b)  for(i=a;i<b;i++)
#define Sort(a)	sort(a.begin(),a.end())
#define rev(a)	reverse(a.begin(),a.end())
#define all(a)	(a).begin(),(a).end()
#define vll vector<long long int>
#define lli long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define db long double
#define M 1000000007
#define pi 3.1415926535897932384626433832795028841971
#define INF 1e18

#define MAX 200005

using namespace std;
lli min(lli a,lli b){return a<b?a:b;}
lli min(lli a,lli b,lli c){a=min(a,b);a=min(a,c);return a;}
lli max(lli a,lli b){return a>b?a:b;}
lli max(lli a,lli b,lli c){a=max(a,b);a=max(a,c);return a;}
lli dsum(lli n){lli ans=0;while(n){ans+=(n%10);n/=10;}return ans;}
lli power(lli a,lli b){lli res=1;while(b){if(b&1) res=res*a;a=a*a;b>>=1;}return res;}
lli power(lli a,lli b,lli m){if(b==0)	return 1;if(b==1)	return a%m;lli res=1;a=a%m;while(b){if(b&1){res=(res*a)%m;}a=((a%m)*(a%m))%m;b>>=1;}return res;}
lli Ceil(lli a,lli b){lli res=a/b;if(a%b!=0)	res++;return res;}

template<typename T>istream &operator>>(istream &is, vector<T> &v) { for (T &t : v) is >> t; return is; }
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v) { for (const T &t : v) {os << t <<" ";} os << '\n'; return os; }

lli dxx[]={1,1,0,-1,-1,-1,0,1};
lli dyy[]={0,1,1,1,0,-1,-1,-1};
lli dx[]={1,0,-1,0};
lli dy[]={0,1,0,-1};

struct pll{
	lli x,y;
};
bool comp(pll a,pll b){
	if(a.x==b.x)	return a.y<b.y;
	else	return a.x<b.x;
}
void solve(lli the)
{
	char ch;
	db aa,bb,cc,dd,xx;
	string s1,s2,s3,str;
    lli i,j,k,a,b,c,d,n,m,l,r,x,y,z,low,high,mid,sum=0,ans=0,temp,t;
    cin >> n;
    pair<db,db>pa[n+1];
    rep(i,1,n+1){
    	cin >> pa[i].first >> pa[i].second;
    }
    sum=1;
    for(i=1;i<=n;i++){
    	sum*=i;
    }
    dd=sum;
    sum*=(n-1);
    a=n*(n-1);a/=2;sum/=a;
    bb=0.0;xx=sum;
    for(i=1;i<=n;i++){
    	for(j=i+1;j<=n;j++){
    		cc=0;
    		cc+=(pa[i].first-pa[j].first)*(pa[i].first-pa[j].first);
    		cc+=(pa[i].second-pa[j].second)*(pa[i].second-pa[j].second);
    		cc=sqrt(cc);
    		cc*=xx;
    		bb+=cc;
    	}
    }
    cc=dd;
    bb/=cc;
    cout << fixed << setprecision(10) << bb;
    
    
}















int main()
{
	long long int t=1,c=1;
	// scanf("%lld",&t);
	while(t--){
		solve(c);
		c++;
	}
	return 0;
}
/* UJJWAL KESHRI */