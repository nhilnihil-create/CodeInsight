//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//Abdulhamid Han
//Bismillahirrahmanirrahim
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█
 
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long lo;
typedef pair< lo,lo > PII;
 
#define fi first
#define se second
#define mp make_pair
#define int long long
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=1;i<=n;i++)
#define mid ((start+end)/2)
#define ort ((bas+son)/2)
 
const lo MAX = -1000000000000000000;
const lo MIN = 1000000000000000000;
const lo inf = 1000000000000000000;
const lo KOK = 100000;
const lo LOG = 30;
const lo li = 500005;
const lo mod = 1000000007;

int n,m,b[li],a[li],k,flag,t,dp[305][305][305];
int cev;
string s;
vector<int> v;

inline int f(int sira,int yuk,int hak){
	int cevv=inf;
	if(hak<0)return inf;
	if(sira>n)return 0;
	if(~dp[sira][yuk][hak])return dp[sira][yuk][hak];
	cevv=min(cevv,f(sira+1,sira,hak)+max(0ll,a[sira]-a[yuk]));
	cevv=min(cevv,f(sira+1,yuk,hak-1));
	return dp[sira][yuk][hak]=cevv;
}

main(void){
	memset(dp,-1,sizeof(dp));
	scanf("%lld %lld",&n,&m);
	FOR{
		scanf("%lld",&a[i]);
	}
	printf("%lld\n",f(1,0,m));
	return 0;
}

