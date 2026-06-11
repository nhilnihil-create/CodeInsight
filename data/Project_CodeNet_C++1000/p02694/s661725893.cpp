#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define dbg(n) cout<<#n<<' '<<n<<endl;
int main(){ 
	ll n;
	cin>>n;
	ll x=100,count=0;
	while(x<n){
		x=(x+x/100);
		count++;
	}
	cout<<count<<endl;
}

