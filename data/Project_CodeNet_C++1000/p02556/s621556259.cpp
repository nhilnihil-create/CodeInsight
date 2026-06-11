#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m,a,b,c,d,p,q;
	cin>>n;
	vector<long long>A(4);
	long long ans=0;
	cin>>p>>q;
	A[0]=p+q,A[1]=p-q,A[2]=-p+q, A[3]=-p-q;
	n--;
	vector<long long>B(4);
	while(n--){
		cin>>p>>q;
		B[0]=p+q,B[1]=p-q,B[2]=-p+q, B[3]=-p-q;
		for(int i=0;i<4;i++) ans=max(ans,abs(A[3-i]+B[i]));
		for(int i=0;i<4;i++) A[i]=max(A[i],B[i]);
	}
	cout<<ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();

}