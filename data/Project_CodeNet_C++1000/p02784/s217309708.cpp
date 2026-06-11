#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
 
ll power(ll a, ll b){//a^b
    ll res=1;
    while(b>0){
        if(b&1){res=(res*a);b--;}
        a=(a*a);
        b>>=1;
    }
    return res;
}
 
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll h,a;
	ll n;
	cin>>h>>n;
	ll sum=0;
	for(ll i=0;i<n;i++){
		ll a;
		cin>>a;
		sum+=a;
	}
	if(sum>=h)
		cout<<"Yes\n";
	else
		cout<<"No\n";
}