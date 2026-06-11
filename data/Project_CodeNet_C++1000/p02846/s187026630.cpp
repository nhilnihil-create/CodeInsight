#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(ll (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll=long long;

ll T1,T2,A1,A2,B1,B2;

int main()
{
	cin>>T1>>T2>>A1>>A2>>B1>>B2;
	ll diff = abs((A1-B1)*T1+(A2-B2)*T2);
	ll gain = abs(A1-B1)*T1;
	if(diff==0){
		cout<<"infinity"<<endl;
		return 0;
	}
	if((A1*T1>B1*T1)==(A1*T1+A2*T2>B1*T1+B2*T2)){
		cout<<0<<endl;
		return 0;
	}
	cout<<2*(gain/diff+1)-1 - (gain%diff==0?1:0)<<endl;
	return 0;
}
