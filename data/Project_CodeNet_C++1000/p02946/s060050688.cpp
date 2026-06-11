#include<iostream>
using namespace std;
int main(){
	int k,x,i;

	cin>>k;
	cin>>x;

	for(i=-k;i<k-1;i++){
		if(-1000000<=(x+i+1) && 1000000>=(x+i+1)){
			cout<<(x+i)+1<<" ";
		}
	}

	cout<<endl;

	return 0;
}