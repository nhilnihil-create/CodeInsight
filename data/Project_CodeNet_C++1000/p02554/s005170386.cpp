#include<bits/stdc++.h>
using namespace std;
long long n;
typedef long long ll;
const int mod=1e9+7;
ll Pow(ll a, ll b, ll m){
	if(b == 0)
		return 1;
	else if(b % 2 == 1)
		return a * Pow(a, b - 1, m) % m;
	else{
		ll num = Pow(a, b/2, m) % m;	//优化 
		return num * num % m;// 不直接写成return binaryPow(a, b/2, m) * binaryPow(a, b/2, m)
	}
	
}
int main()
{
	cin>>n;
	cout<<((Pow(10,n,mod)-Pow(9,n,mod)-Pow(9,n,mod)+Pow(8,n,mod))%mod+mod)%mod;
}