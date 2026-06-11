#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main(){
	int n;cin>>n;
	if(__builtin_popcount(n)==1){
		puts("No");return 0;
	}
	puts("Yes");
	vector<P>v;
	int a[]{1+n,2,3,1,2+n,3+n};
	rep(i,5)v.push_back(P(a[i],a[i+1]));
	for(int i=4;i+1<=n;i+=2){
		v.push_back(P(i,i+1));
		v.push_back(P(i+1,1));
		v.push_back(P(1,n+i));
		v.push_back(P(n+i,n+i+1));
	}
	if(n%2==0){
		int x=n^(n-1)^1;
		v.push_back(P(n,n-1));
		if(x%2==0){
			v.push_back(P(x+n,n*2));
		}
		else{
			v.push_back(P(x,n*2));
		}
	}
	for(auto p:v){
		printf("%d %d\n",p.first,p.second);
	}
}