#include <iostream>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main(){
	int N,M,K;
	cin>>N>>M>>K;
	long long A[N],B[M],a[N+1],b[M+1];
	rep(i,N) cin>>A[i];
	rep(i,M) cin>>B[i];

	a[0]=0;
	b[0]=0;
	for(int i=1;i<=N;i++)a[i] = a[i-1] + A[i-1];

	for(int j=1;j<=M;j++)b[j] = b[j-1] + B[j-1];

	int ans=0;
	int j=M;
	rep(i,N+1){
		if(K-a[i]<0)break;
		
		while(b[j]>K-a[i] && j>=0){
			j-=1;
		}
		ans = max(ans,i+j);//ansよりi+jが大きかったら更新
		if(i==N) break;
	}
	cout<<ans<<endl;

}