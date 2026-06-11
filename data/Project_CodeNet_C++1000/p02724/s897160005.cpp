#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
#include<queue> 
using namespace std;
int main(){
//	freopen("x.txt","r",stdin);
	int n;
	cin>>n;
	cout<<n/500*1000+n%500/5*5<<endl; 
	return 0;
}