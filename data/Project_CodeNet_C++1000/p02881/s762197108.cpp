#include<bits/stdc++.h>
#define lint long long int
using namespace std;
template<typename T1,typename T2>bool chmin(T1& a,T2 b){if(a>b){a=b;return true;}else{return false;}}


lint inf=pow(2,50);

int main(){
	cin.tie(0);ios::sync_with_stdio(false);cout<<std::fixed<<std::setprecision(19);
	lint n;
	scanf("%lld",&n);
	lint ans=n-1;
	lint hoge=sqrt(n);
	for(lint i=1;i<=hoge;i++)if(n%i==0)chmin(ans,i-2+(n/i));
	printf("%ld",ans);
	return 0;
}
