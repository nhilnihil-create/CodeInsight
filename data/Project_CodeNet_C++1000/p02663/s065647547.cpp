#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int main(){
	ll h1,m1,h2,m2,k; cin>>h1>>m1>>h2>>m2>>k;
	ll s=h1*60+m1;
	ll e=h2*60+m2;
	e-=k;
	cout<<e-s<<endl;
}
