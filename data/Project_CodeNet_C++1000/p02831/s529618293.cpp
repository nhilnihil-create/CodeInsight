#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
ll n,t,x,y,m,q;
ll gcd(ll x,ll y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}
int main(){
      ios_base::sync_with_stdio(false); cin.tie(NULL);
      cin>>n>>x;
      cout<<(n*x)/gcd(n,x);
      
}