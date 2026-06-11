// Author : Bisma Kho (ビスマコー)
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb(a) push_back(a)
#define fi first
#define se second
#define rep(a,b,c) for(int a = b ;a<=c;a++)
#define repn(a,b,c) for(int a = b ; a>=c ; a--)
#define FOR(a,b,c) for(int a = b ; a<c ;a++)
#define mem(a,b) memset(a,b , sizeof(a))
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define size(a) ((int)a.size())
#define ii int
#define umap unordered_map
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a * b / gcd(a,b)
const int INF=0x3f3f3f3f;
const int maxn=5e5+10;
const int maxk=30;
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define  max(a,b) (a > b) ? a : b;
#define  min(a,b) (a > b) ? b : a;




void solve(){

	ll a;
	cin>>a;

	ll ans = a / 2;

	if(a % 2 ==0 ) ans -=1;

	cout<<ans<<endl;

}


int main() { 
	fastio

	solve();

	
   exit(0); 
} 	
