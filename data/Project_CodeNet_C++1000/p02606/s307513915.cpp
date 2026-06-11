#include<iostream>
using namespace std;
int main(){
	int n,m,a,cnt=0;
	cin>>n>>m>>a;
	for(int i=n;i<=m;i++){
		if(i%a==0)
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}