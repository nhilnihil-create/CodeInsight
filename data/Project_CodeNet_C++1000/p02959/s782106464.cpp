#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  long long int N,ans;
    cin>>N;
	vector<long long int> A(N+1);
	vector<long long int> B(N);
	rep(i,N+1) cin>>A[i];
	rep(i,N) cin>>B[i];
	ans=0;
	for(int i=0;i<N;i++){
	  int now=B[i];
		if (A[i]<B[i]){
		  now-=A[i];
			ans+=A[i];
			if (A[i+1]>=now){
				A[i+1]-=now;
				ans+=now;
			}
			else{
                ans+=A[i+1];
				A[i+1]=0;
			}
		}
		else{
		  ans+=B[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}