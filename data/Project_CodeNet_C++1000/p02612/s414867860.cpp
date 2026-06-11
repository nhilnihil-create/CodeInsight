#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}


int main(){
	int n;
	cin>>n;
	if(n%1000==0){
		cout<<0<<endl;
	}
	else{
		cout<<1000-n%1000<<endl;
	}
	return 0;
}
