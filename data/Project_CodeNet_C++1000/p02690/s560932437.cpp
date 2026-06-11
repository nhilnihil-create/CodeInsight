#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#define ll long long int
#define ld long double
#define pb push_back
#define pll pair<ll,ll>
#define pint pair<int,int>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define mod 1000000007
#define MAX 100000000
#define endl '\n'
#define mp make_pair
#define INF INT_MAX
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ff first
#define ss second
#define ps(x,y) fixed<<setprecision(y)<<x
#define setbits(x) __builtin_popcountll(x)			//counts no of ones in binary representation
#define w(t) 	int t; cin>>t; while(t--)
#define pi 3.141592653589793238
#define sortt(v)  sort(v.begin(),v.end())
#define lb(v,x) std::lower_bound(v.begin(),v.end(),x)
#define ub(v,x) std::upper_bound(v.begin(),v.end(),x)

using namespace std;

ll power(int a,int n){
	ll ans=1;
	while(n){
		if(n%2==0){
			a*=a;
			n/=2;
		}
		else{
			ans*=a;
			n--;
		}
	}
	return ans;
}

int main(){
	fast;
	int x;
	cin>>x;
	if(x==1){
		cout<<1<<' '<<0;
		return 0;
	}
	ll a,b;
	bool flag=1;
	int i,j;
	for( i=-2500;i<=2500;i++){
		a=power(i,5);
		for( j=-2500;j<=2500;j++){
			b=power(j,5);
			if(a-b==x){
				flag=0;
				break;
			}
		}
		if(!flag)	break;
	}
	cout<<i<<' '<<j;
}