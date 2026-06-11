#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int siz=2e5+1;
const long inf=1e9;
int main(){
	int N; cin>>N;
	long A[N],B[N];
	rep(i,0,N) cin>>A[i]>>B[i];
	sort(A,A+N); sort(B,B+N);
	if(N % 2 == 0) cout<<(B[N/2-1] + B[N/2]) - (A[N/2-1] + A[N/2]) + 1<<endl;
	else cout<<B[N/2] - A[N/2] + 1<<endl;
}