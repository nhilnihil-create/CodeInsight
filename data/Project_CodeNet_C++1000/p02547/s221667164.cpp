#include<iostream>
using namespace std;
int main(){
	int n,c=0,r=0;
	cin>>n;
	for (int N=0;N<n;N++){
		int a,b;
		cin>>a>>b;
		if(a==b){
			c++;
		}else{
			c=0;
		}

		if(c>=3){
			r=1;
		}

	}
	if(r==1) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}