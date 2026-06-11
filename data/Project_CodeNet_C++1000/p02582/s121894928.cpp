#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
using namespace std;
// LIVE AND LET OTHERS LIVE.
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define endl '\n'
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ai(arr,n) for(int i=0;i<n;i++)cin>>arr[i];
#define ao(arr) for(auto wtf:arr) cout<<wtf<<" ";
#define mi(arr,m,n) for(int i=0;i<m;i++){ for(int j=0;j<n;j++) cin>>arr[i][j];}
#define mo(arr,m,n) for(int i=0;i<m;i++){ for(int j=0;j<n;j++) cout<<arr[i][j]<<" "; cout<<endl;}
#define countsetbits(x) __builtin_popcount(x)
#define ll long long
#define wtf cout<<"I AM EXECUTING"<<endl
#define testcases int asdf; cin>>asdf; while(asdf--)
#define vi vector<int>
#define si set<int>
#define vc vector<char>
#define sc set<char>
#define vll vector<long long int>
#define vs vector<string>
#define vpp vector<pair<int,int>> 
#define vppo(prs) for(auto x:prs){cout<<x.first<<" "<<x.second<<endl;}
#define For(__,$$,adfdf) for(int __ = $$; __<adfdf;__++)
#define mod (ll)1e7+9
vll  primeFactors(ll int n)  {  
	vll a;
    while (n % 2 == 0)  {  
		a.pb(2);
        n = n/2;  
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)  {  
        while (n % i == 0)  {  
            a.pb(i);
            n = n/i;  
		}
	}
    if (n > 2)  
        a.pb(n);
    return a;
}  
ll int mpow(ll int base,ll  int exp) {
	base %= mod;
	ll int result = 1ll;
	while (exp > 0) {
	if (exp & 1ll) result = ((ll)result * base) % mod;
	base = ((ll)base * base) % mod;
	exp >>= 1;
	}
	return result;
}
string sconvert(ll int n)
{
	stringstream ss;
	ss<<n;
	string str = ss.str();
	return str;
}
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second > b.second); 
}
template<typename KeyType, typename ValueType>  // for finding max element in the map.
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>; 
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  }); 
}

ll modmul(ll a, ll b) {
    return ((a%mod) * (b%mod)) % mod;
}
 
ll modadd(ll a , ll b){
    return((a%mod)+(b%mod)+mod)%mod;
}
 
ll modsub(ll a , ll b){
    return((a%mod) - (b%mod) + mod)%mod;
}
 
ll fastexpo(ll a,ll b ,ll MOD = mod){
    a = a%MOD;
    //b = b%(mod-1); // if mod is prime then only
    ll ans=1;
    while(b){
        if(b&1)
            ans=(ans*1ll*a)%MOD;
        a=(a*1ll*a)%MOD;
        b=b/2;
        }
    return ans;
 }
 
void  single()
{
	int answer=INT_MIN;
	string str;
	cin>>str;
	int n=str.length();
	int count=0;
	For(i,0,n){
		if(str[i]=='R')
		count++;
		else{
		answer = max(answer,count);
		count=0;
	} 
	}
	answer=max(count,answer);
	cout<<answer<<endl;
	return;
}
void multiple()
{
	testcases
    {
		single();
	}
}

int main()
{
  IOS;
 // freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  single();
}













