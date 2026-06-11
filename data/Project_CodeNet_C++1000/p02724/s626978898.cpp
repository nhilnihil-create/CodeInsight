#include<bits/stdc++.h>
#define ll long long int
#define l(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main(){
	ll n;
	cin>>n;
	cout<<(n/500)*1000+(n%500)/5 *5<<"\n";
}