#include <bits/stdc++.h>
#define ll long long
#define pb push_back
ll mod=1000000005;
using namespace std;

int main(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;

	
	ll p = a*c;
	ll q=a*d;
	ll r=b*c;
	ll s=b*d;

	cout<<max(p,max(q,max(r,s)))<<endl;
}