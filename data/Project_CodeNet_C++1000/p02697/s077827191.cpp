#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=n/2,j=i+1,k=1;k<=m;k++,i--,j++){
		if(n%2==0&&(j-i==n/2||j-i==n/2+1))j++;
		cout<<i<<' '<<j<<endl;
	}
	return 0;
}