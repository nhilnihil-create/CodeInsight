#include<bits/stdc++.h>
using namespace std;

int main(){
	while(1){	
	int n,s[1000],sa,h;
	cin>>n;
	if(n==0) break;
	for(int i=0;i<n;i++)
		cin>>s[i];
	sa=s[1]-s[0];
	if(sa<0) sa=sa*(-1);
	for(int i=0;i<n-1;i++){
		for(int l=i+1;l<n;l++){
			h=s[l]-s[i];
			if(h<0) h=h*(-1);
			if(sa>=h) sa=h;
		}
	}
	cout<<sa<<endl;
	}	
    return 0;
}
