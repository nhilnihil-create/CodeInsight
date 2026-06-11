#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define el(a) (a).end()-(a).begin()
#define mod 1000000007
#define inf 2147483647
#define range(x,a,b) (a)<=x&&x<=(b)
int main(){
	int n;
	cin>>n;
	if(n%10==3){
		cout<<"bon";
		return 0;
	}
	if(n%10==0||n%10==1||n%10==6||n%10==8){
		cout<<"pon";
		return 0;
	}
	cout<<"hon";
	return 0;
}