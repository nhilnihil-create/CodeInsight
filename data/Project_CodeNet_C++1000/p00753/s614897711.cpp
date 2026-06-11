#include<iostream>
#include<string>
using namespace std;
int main(){
	int n,count;
	while(true){
	cin>>n;
	if(n==0)
		break;
	count=0;
	for(int i=n+1;i<=2*n;i++){
		bool t=true;
		for(int j=2;j*j<=i;j++){
			if(i%j==0)
				t=false;
		}
		if(t==true)
			count++;
	}
	cout<<count<<endl;
	}
    return 0;
}