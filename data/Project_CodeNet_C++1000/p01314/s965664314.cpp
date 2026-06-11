#include <bits/stdc++.h>
using namespace std;
int main(){
	int s,n,c;
	while(cin>>n,n){
		c=0;for(int i=1;i<n/2+1;i++){s=i;for(int j=1;s<n;j++){s+=(i+j);if(s==n){c++;break;}}}
		cout<<c<<endl;
	}
}