#include<iostream>
using namespace std;
int main(){
	int M,D;
	int d1,d10,count=0;
	cin>>M>>D;
	for(int i=1;i<=M;i++){
		for(int j=1;j<=D;j++){
			d1 = j%10;
			d10 = (j-j%10)/10;
			if(d1>=2 && d10>=2 && i==d1*d10)count++;
		}
	}
	cout<<count<<endl;
	return 0;
}