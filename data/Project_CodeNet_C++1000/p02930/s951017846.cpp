#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
set<string> c;
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=100000000000000000;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
map<ll,ll> mp;
int n;
int tmp;
int check(int a,int b){
    for(int i=0;i<32;i++){
	if( ( (a>>i)&1 ) != ( (b>>i)&1 ) ) return i; 
    }
    return 0;
}

int main(){
    ll n;
    cin>>n;
    for(int i=0;i<n-1;i++){
	for(int j=i+1;j<n;j++){
	    cout<<1+check(i,j)<<" ";
	}
	cout<<endl;
    }
}
