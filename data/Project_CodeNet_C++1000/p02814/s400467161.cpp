#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define el(a) (a).end()-(a).begin()

int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	in(a,n);
	ll b=a[0],c=a[0];
	rep(i,n){
		b=gcd(b,a[i]);
		c=lcm(c,a[i]);
	}
	b/=2;
	c/=2;
	if((c/b)%2==0){
		cout<<0;
		return 0;
	}
	cout << (m/c+1)/2;
	return 0;
}