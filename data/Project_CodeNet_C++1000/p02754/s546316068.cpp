#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;


int main() {
	// violinista forever xd
	ios::sync_with_stdio(0),cin.tie(0);
	
	ll n, a, b,tmp,aux,rta,tmp2;
    cin>>n>>a>>b;
    tmp = n / (a + b);
    aux = n % (a + b);
    tmp2 = min(a, aux);
    rta = a * tmp + tmp2;
	cout<<rta<<endl;
	
	return 0;
}