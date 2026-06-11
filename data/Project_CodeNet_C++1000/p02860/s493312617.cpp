#include <bits/stdc++.h>
 
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define ff first
//#define ss second
#define rep(i,a,b)	for(ll  i=a;i<b;i++)
#define hello777 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#include <string>
#define pie 3.14159265358979323846
constexpr int MOD = 1e9+7;
const int N= 50000;
using namespace std;


ll gcd(int a, int b)
{ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 
 
ll lcm(int a, int b)  
 {  
    return a/gcd(a, b) *b;  
 }
  
int prime(int n)
{
	rep(i,2,n+1)
	{
		if(n%i==0)return i;
	}
	
}


void solve() 
{
	ll n;
	cin>>n;
	string s;
	cin>>s;
	if(n==1 || n%2==1)
	{
		cout<<"No"<<endl;
		return ;
	}
	if(s.substr(0,n/2)==s.substr(n/2,n/2))cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

int main()
{
	hello777;
	int q=1;
//    cin>>q;
    while(q--)
    {   
      solve();
    }
}