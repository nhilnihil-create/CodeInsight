#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1;
	int s=0,ma=-1;
	while(i<n){
		i++;
		if(a[i]>a[i-1]){
			ma=max(ma,s);
			s=0;
			continue;
		}
		s++;
	}
	ma=max(ma,s);
	cout<<ma<<endl;
	return 0;
}
