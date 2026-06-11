#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	int a[200100],b[200100];
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>a[i]>>b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	
	if(n%2==0){
	    cout<<(b[n/2]+b[n/2-1])-(a[n/2]+a[n/2-1])+1<<endl;    
	}else{
	    cout<<b[n/2]-a[n/2]+1<<endl;
	}
	return 0;
}
