//https://atcoder.jp/contests/nomura2020/tasks/nomura2020_d
#include<bits/stdc++.h>
using namespace std;
int h1,m1,h2,m2,k;
signed main(){
	scanf("%d%d%d%d%d",&h1,&m1,&h2,&m2,&k);
	int s=h1*60+m1,t=h2*60+m2;
	cout<<max(0,t-s-k);
	
	return 0;
} 