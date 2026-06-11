#include <iostream>
using namespace std;
int main(){
	int a,b,n;
	int A=0;
	int B=0;
	while(1){
		A=0;
		B=0;
		cin>>n;
		if(n==0) break;
		for(int i=0; i<n; i++){
			cin>>a>>b;
			if(a>b){
				A+=a;
				A+=b;
			}else if(a<b){
				B+=a;
				B+=b;
			}else if(a==b){
				A+=a;
				B+=b;
			}

			
		}
		cout<<A<<" "<<B<<endl;
	}
}