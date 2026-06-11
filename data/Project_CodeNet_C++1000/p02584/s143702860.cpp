//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 
 
 
ll MOD=1e9 + 7;
int OO=1e9 + 1;
const int N=1e3 + 10,M=20;
char arr[N][N];
int vis[N][N];


ll n,m,k,T;
int a,b,c,d;
int l,r,mid;



int main(){
	IO
	//freopen("in.txt","r",stdin);
	
	cin>>n>>k>>m;
	ll val = abs(n)/m;
	if(n < 0)
		n += 1ll*min(k,++val)*m;
	else
		n -= 1ll*min(k,val)*m;
	
	k-=min(k,val);

	if(k&1)
		n-=m;
	cout<<abs(n)<<endl;
}

 