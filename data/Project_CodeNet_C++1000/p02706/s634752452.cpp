#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	int x,bwl=0;
	for(int i=1;i<=m;++i){
		scanf("%d",&x);
		bwl+=x;
	}
	cout<<(bwl<=n ? n-bwl : -1)<<endl;
	return 0;
}


