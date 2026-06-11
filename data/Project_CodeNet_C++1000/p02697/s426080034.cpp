#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array);

int main(){

	ll n,m;
	cin>>n>>m;
	ll left=1;
	ll right=n-1;
	ll cnt=0;
	if(n%2==1){
	fo(i,m){
		cout<<left<<" "<< right <<endl;
		left++;
		right--;
	}
}
else{
	ll init;
	if((n/2)%2==0) init=n/2-1;
	else init=n/2;
	ll first=1;
	ll total=(init- first)/2;
	ll l,r;
	l=1;
	r=init;
	total=min(total,m);

	fo(i,total){
		cout<<l<<" "<<r<<endl;
		l++;
		r--;

	}
	total=m-total;

	l=init+1;
	r=n-1;
	fo(i,total){
		cout<<l<<" "<<r<<endl;
		l++;
		r--;
	}





}





}
