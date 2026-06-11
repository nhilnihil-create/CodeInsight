#include <iostream>
using namespace std;

int main(){
	int a[10000],b[10000],c=0;
	cin>>a[0]>>b[0];
	while(a[c]!=0&&b[c]!=0){
		cin>>a[c+1]>>b[c+1];
		c++;
	}
	for(int d=0;d<c;d++){
		for(int i=0;i<a[d];i++){
			for(int j=0;j<b[d];j++){
				cout<<'#';
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}