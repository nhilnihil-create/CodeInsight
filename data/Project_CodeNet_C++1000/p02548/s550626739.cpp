#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	int N,ans=0;
	cin>>N;
	int C[N+1]={0};
	for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j+=i)C[j]++;
	}
	for(int i=1;i<N;i++)ans+=C[i];
	cout<<ans;
	return 0;
}