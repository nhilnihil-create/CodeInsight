#include<iostream>
#include<math.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define lrep(i,n) for(long int i=0;i<(n);i++)
using namespace std;
int main(){
	long int n;
	cin >>n;
	long long int a,ans=1;
	lrep(i,n){
		cin >>a;
		if(a==0){
			ans=0;
			break;
		}
		if(ans==-1)continue;
		if(a>1000000000000000000/ans){
			ans=-1;
			continue;
		}
		ans*=a;
	}
	cout<<ans;
	return 0;
}

