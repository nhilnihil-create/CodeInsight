#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define mod 1000000007
#define inf 2147483647
#define range(x,a,b) (a)<=x&&x<=(b)
ll pow5(ll a){
	return a*a*a*a*a;
}
int main(){
	int x;
	cin>>x;
	ll a,b,remainder=1;
	while(1){
		a=1;
		b=a-remainder;
		while(a<abs(b)||pow5(a)-pow5(b)<=x){
			if(pow5(a)-pow5(b)==x){
				cout<<a<<" "<<b;
				return 0;
			}
			a++;
			b++;
		}
		remainder++;
	}
	return 0;
}