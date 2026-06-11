#include<bits/stdc++.h>
#define ll long long int 
#define w(x) int x; cin>>x; while(x--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll h;
	ll c=2,s=1;
	cin>>h;
	while(h){
		if(h==1)
			break;
		h=h/2;
		s+=c;
		c*=2;
	}
	cout<<s;
	

}