#include<bits/stdc++.h>
using namespace std;
long long n,m,a,num;
int main(){
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>a;
		num+=a;
	}
	if (num>n)
		cout<<-1<<endl;
	else
		cout<<n-num<<endl;
	return 0;
}