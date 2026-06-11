#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
int main(){
	ll a,b,c,d;
	ll sum;
	cin>>a>>b>>c>>d;
	sum = max(b * c,b * d);
	sum = max(sum,a * c);
	sum = max(sum,a * d);
	cout<<sum<<endl;
	return 0;
}