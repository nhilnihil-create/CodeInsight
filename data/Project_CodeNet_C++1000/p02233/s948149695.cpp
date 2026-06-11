#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define MAX_N 45
vector<int> v(MAX_N,-1);

int fibo(int n){
	if(v[n]<0){
		v[n]=fibo(n-1)+fibo(n-2);
	}
	return v[n];
}


int main(){
	int n;
	cin>>n;
	v[0]=1;
	v[1]=1;
	cout<<fibo(n)<<endl;
	return 0;
}