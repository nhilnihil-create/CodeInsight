#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+10;
int m,d=0;
int main(){
	cin>>m>>d;
	int ans=0;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=d;++j){
			if(j%10<2) continue;
			if((j/10)<2) continue;
			if((j%10)*(j/10)==i) ++ans;
		}
	}
	cout<<ans<<endl;
}