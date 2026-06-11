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
	int n,k;
	cin>>n>>k;
	int sunuke[n];
	rep(i,n)sunuke[i]=1;
	int d,a;
	rep(i,k){
		cin>>d;
		rep(j,d){
			cin>>a;
			sunuke[a-1]=0;
		}
	}
	int count=0;
	rep(i,n)count+=sunuke[i];
	cout<<count;
	return 0;
}