#include <iostream>
using namespace std;

int main() {
int N; int X;
cin>>N>>X;
int cor[N+1];
cor[0]=0;
int ab;
for(int x=0;x<N+1;x++){
	cin>>ab;
	cor[x+1]=cor[x]+ab;
}
int ans=0;
for(int a=0;a<N+1;++a){
	if(cor[a]<=X){
		ans+=1;
	}
}
cout<<ans;

	return 0;
}