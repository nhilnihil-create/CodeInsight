#include <iostream>
using namespace std;

int main(){
	int a[10000],b[10000],c=0;
	cin>>a[0]>>b[0];
	while(a[c]!=0||
		b[c]!=0){
		cin>>a[c+1]>>b[c+1];
		c++;
	}
	for(int d=0;d<c;d++){
		for(int e=0;e<b[d];e++) cout<<'#';
		cout<<endl;
		for(int i=2;i<a[d];i++){
			cout<<'#';
			for(int j=2;j<b[d];j++){
				cout<<'.';
			}
			cout<<'#'<<endl;
		}
		for(int f=0;f<b[d];f++) cout<<'#';
		cout<<endl<<endl;;
	}
	return 0;
}