#include <iostream>

using namespace std;

int main(){

	int A,B,m;
	cin>>A>>B>>m;
	int a[A];
	int b[B];
	int c[m];
	int x[m];
	int y[m];
	int sa=1000000;
	int sb=1000000;
	int ans;
	for(int i=0;i<A;i++){
	
		cin>>a[i];
		if(a[i]<sa){
		
			sa=a[i];
		}
	}
	for(int i=0;i<B;i++){

		cin>>b[i];
		if(b[i]<sb){
		
			sb=b[i];
		}
		
	}
	ans=sa+sb;
	for(int i=0;i<m;i++){
	
		cin>>x[i]>>y[i]>>c[i];
		if(a[x[i]-1]+b[y[i]-1]-c[i]<ans){
		
			ans=a[x[i]-1]+b[y[i]-1]-c[i];
		}
	}

	cout<<ans;
	return 0;

}
