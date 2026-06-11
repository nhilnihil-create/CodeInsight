#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;

int main(){
	LL a,b,c,d;
	cin>>a>>b>>c>>d;
	LL a1=a*c;
	LL a2=a*d;
	LL a3=b*c;
	LL a4=b*d;
	a1=max(a1,a2);
	a1=max(a1,a3);
	a1=max(a1,a4);
	cout<<a1<<endl;
	return 0;
}