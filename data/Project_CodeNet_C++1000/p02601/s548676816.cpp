#include<iostream>
using namespace std;

int main(){
	long long int a,b,c;
	long long int k;
	cin>>a>>b>>c>>k;
	while(k--){
		if(a>=b){
		
			b*=2;
		}
		else if(b>=c){
		
			c*=2;
		}
		
	}
		 if(a<b&&b<c){
			cout<<"Yes"<<endl;
			return 0;
		}
		cout<<"No"<<endl;
		return 0;
}
