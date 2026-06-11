#include <iostream>
using namespace std;
int main(){
	int n,pa,pb,a,b;
	while(cin>>n){
		if(n==0){break;}
		pa=pb=0;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			if(a>b){
				pa+=a+b;
			}else if(b>a){
				pb+=a+b;
			}else{
				pa+=a;
				pb+=b;
			}
		}
		cout<<pa<<" "<<pb<<endl;
	}
	return 0;
}