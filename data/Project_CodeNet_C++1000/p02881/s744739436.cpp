#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define powerof2 ()
#define mp make_pair
#define pi acos(-1)
using ll = long long;
const ll M = 1000000007;
const ll M1= 998244353;
using vl = vector<ll>;
using pll =  pair<ll,ll>;
/*ll power(ll x,ll y){
	if(y==0)
		return 1;
	ll res=power(x,y/2);
	res=(res*res);
	if(y&1)
		res=(res*x);
	return res;
}
 
ll powermod(ll x,ll y,ll mod){
	if(y==0)
		return 1;
	ll res=powermod(x,y/2,mod);
	res=(res*res)%mod;
	if(y&1)
		res=(res*x)%mod;
	return res;
}
ll binarysearch(ll va)
{
	ll n=1;
	ll l=va+1,u=n;
	ll st=num.order_of_key(va);
	while(l+1<u)
	{
		m=(l+u)/2;
		ll in=num.order_of_key(m);
		if(in-st==m-va)
		{
			l=m;
		}
		else
		{
            u=m;
		}
	}
	if(num1.find(l)==num1.end())
		return l;
	return u;
}
bool IsPrime(long long number) 
{
  long long root = sqrt(number) ;
   for(long long i=2; i<=root; i++) 
   {
      if(number%i == 0)
          return false;
   } 
   return true;
} */
void solve(){
	long long n;
	cin>>n;
	vector<pair<long long,long long> > v;
	for(ll i=1;i<=sqrt(n);i++){
        if(n%i==0){
            v.push_back(make_pair(i, n/i));
        }
    }
	ll mn=1e12;
	for(auto i:v){
         if(i.first+i.second-2<mn){
			 mn=i.first + i.second -2;
		 }}
		 cout<<mn<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
 
    for(int i=1;i<=t;i++)
    {//cout<<"Case #"<<i<<": ";
    solve();}
    return 0;
}