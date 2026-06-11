#include <bits/stdc++.h>
using namespace std;
int N,K,p[1001],x;
int main() {
	cin>>N>>K;
	for(int i=1;i<=N;i++) {
		cin>>p[i];
	}
	sort(p+1,p+N+1);
	for(int i=1;i<=K;i++) {
		x+=p[i];
	}
	cout<<x<<endl;
}
