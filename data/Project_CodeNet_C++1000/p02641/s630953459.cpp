#include<bits/stdc++.h>
#include <vector>
using namespace std;
#define vi vector<int>
#define pb push_back
#define p push
#define sll stack<long long>
#define qll queue<long long>
#define vll vector<long long>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define fork(n) for(int k=0;k<n;k++)
#define fori1(n) for(int i=1;i<n;i++)
#define f(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define pi 3.14159265358979323
#include <math.h>
#define yn(n) if(n)cout<<"yes\n";else cout<<"no\n";
#define Yn(n) if(n)cout<<"Yes\n";else cout<<"No\n";
#define YN(n) if(n)cout<<"YES\n";else cout<<"NO\n";
#define mp   make_pair 
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
ll lcm(ll a, ll b){return a*b/gcd(a, b);}

vll r,b,g;ll ans=0;

ll md(ll n){
	if(n>0)return n;
	else return -n;
}



string str,str2;
void solve(){
    ll x,n;cin>>x>>n;
    set<ll> s;
    fori(n){
        ll a;cin>>a;
        s.insert(a);
    }
    int i=0;n=x;
    while(true){
        if(*(s.lower_bound(n-i))!=(n-i)){
            cout<<n-i;break;
        }
        if(*(s.lower_bound(n+i))!=(n+i)){
            cout<<n+i;break;
        }
        i++;
    }
}


int main(){

 
    	
	int t;
	t=1;
	//cin >> t;
	while(t--){
		solve();
		
	}
	
	
	//cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

}