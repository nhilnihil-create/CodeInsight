#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 1;i<=n;i++)
#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll solve(ll a,ll b,ll c){
	return gcd(gcd(a,b),c);
}

int main(){

	ll k;
	cin>>k;
	ll sum = 0;
	f(i,k){
		f(j,k){
			f(t,k){
				sum = sum + solve(i,j,t);
			}
		}
	}
	cout<<sum;
	

}