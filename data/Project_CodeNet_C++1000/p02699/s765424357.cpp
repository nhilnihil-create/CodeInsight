#include <bits/stdc++.h> 
using namespace std; 
#define vll vector<long long>
#define mll map<long long,long long>
#define pb push_back
typedef  long long ll;
typedef long double ld;
long double pi=3.14159265358979323846;

vll al[500005];
ll vis[500005],color[500005],I[101][101];

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

bool isPrime(int n)
{
    if (n<=1) return false; 
    if (n<=3) return true; 
    if (n%2==0||n%3==0) return false; 
    for (int i=5;i*i<=n;i=i+6) if (n%i==0||n%(i+2)==0) return false; 
    return true; 
}

ll bpow(ll n, ll po)
{
	ll res=1;
	while(po>0)
	{
		if(po%2)
		{
			res*=n;
			po--;
		}
		else
		{
			n*=n;
			po/=2;
		}
	}
	return res;
}

ll binpow(ll n, ll po, ll mod)
{
	ll res=1;
	while(po>0)
	{
		if(po%2)
		{
			res=(res*n)%mod;
			po--;
		}
		else
		{
			n=(n*n)%mod;
			po/=2;
		}
	}
	return res;
}

ll swap(ll a, ll b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}

ll fact(ll n) { 
   if ((n==0)||(n==1))
      return 1;
   else
      return n*fact(n-1);
}

ll C(ll n, ll r) {
    if(r > n - r) r = n - r; 
    ll ans = 1;
    ll i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
        ans=ans%1000000007;
    }

    return ans;
}

//bool bipartite_dfs(ll node, ll flag)
//{
//	vis[node]=1;
//	ll cflag=flag;
//	color[node]=cflag;
//	for(ll child : al[node])
//	{
//		if(!vis[child])
//		{
//			bool n=bipartite_dfs(child,1-cflag);
//			if(n==false) return false;
//		}
//		else if(color[child]==color[node]) return false;
//	}
//	return true;
//}

void mmul(ll A[][101], ll B[][101], ll dim)
{
	ll res[dim][dim];
	for(ll i=0;i<dim;i++) for(ll j=0;j<dim;j++)
	{
		res[i][j]=0;
		for(ll k=0;k<dim;k++) res[i][j]=(res[i][j]+A[i][k]*B[k][j])%1000000007;
	}
	for(ll i=0;i<dim;i++) for(ll j=0;j<dim;j++) A[i][j]=res[i][j];
}

void mpow(ll A[][101],ll dim, ll po)
{
	for(ll i=0;i<dim;i++) for(ll j=0;j<dim;j++)
	{
		if(i==j) I[i][j]=1;
		else I[i][j]=0;
	}
	while(po>0)
	{
		if(po%2==1)
		{
			mmul(I,A,dim);
			po--;
		}
		else
		{
			mmul(A,A,dim);
			po/=2;
		}
	}
	for(ll i=0;i<dim;i++) for(ll j=0;j<dim;j++) A[i][j]=I[i][j];
}



int main()
{
	ll a,b;
	cin>>a>>b;
	if(b>=a) cout<<"unsafe";
	else cout<<"safe";
}
