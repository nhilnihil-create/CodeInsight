#include<iostream>
using namespace std;

int main(){
	int a[4],b[4];
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]){
		int hit=0,blow=0,f=0,b;
		for(int i=0;i<4;i++)f |= 1<<a[i];
		for(int i=0;i<4;i++){
			cin>>b;
			if(b==a[i])hit++;
			else if(1<<b & f)blow++;
		}
		cout<<hit<<' '<<blow<<endl;
	}
	return 0;
}