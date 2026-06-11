#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
bool a[300000]={0};
a[1]=1;
for(int i=2;i<150001;i++){
	if(a[i]==1) continue;
	int j=2*i;
	while(j<300000){
		a[j]=1;
		j=j+i;
	}
}
int n;
while(cin>>n && n!=0){
int ans=0;	
	for(int i=n+1;i<=2*n;i++){
	if(a[i]==0) ans++;	
	}

cout<<ans<<endl;
}

	return 0;
}