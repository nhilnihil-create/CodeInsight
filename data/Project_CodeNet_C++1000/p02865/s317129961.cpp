#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,num=0;
	cin>>n;
	for(int i=1;i<=n/2;i++){
		if(i!=n-i) num++;
	}
	cout<<num<<endl;
}