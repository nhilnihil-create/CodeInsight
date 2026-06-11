#include<bits/stdc++.h>
#define int long long
using namespace std;

int N,M,V,P;
int A[100005],S;
bool cmp(int a,int b){return a>b;}

bool check(int i){
	if(i<=P) return 1;
	if(A[i]+M<A[P]) return 0;
	if(V<=P+N-i) return 1;
	return ((V-P-N+i)*M-S-1)/(i-P)<=A[i]+M-A[P]-1;
}

int ans;

signed main(){
	scanf("%d%d%d%d",&N,&M,&V,&P);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);
	sort(A+1,A+N+1,cmp);
	for(int i=P+1;i<=N;i++){
		if(check(i)) ans++;
		S+=A[P]-A[i];
	}
	printf("%d\n",ans+P);
	check(N);
}