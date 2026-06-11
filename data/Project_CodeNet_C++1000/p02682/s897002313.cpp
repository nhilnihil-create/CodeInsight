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
int main(){
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	int sum=0;
	if(k<=a)cout<<k;
	else if(k<=a+b)cout<<a;
	else cout<<2*a+b-k;
	return 0;
}