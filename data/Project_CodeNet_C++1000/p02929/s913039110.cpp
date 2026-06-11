#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=1e5;
const int inf=1e9;
int main(){
	int N;string s;cin>>N>>s;
	int L[2*N],R[2*N];
	long res = 1; int cnt = 0; bool flag = true;
	rep(i,0,2*N){
		R[i] = (s[i] == 'W') ^ i % 2;
		L[i] = R[i] ^ 1;
		cnt += L[i] - R[i];
		if(cnt < 0) flag = false;
		if(R[i] == 1) (res *= cnt + 1) %= mod;
	}
	if(!flag || cnt > 0){
		cout<<0<<endl;
		return 0;
	}
	rep(i,1,N+1) (res *= i) %= mod;
	cout<<res<<endl;
}