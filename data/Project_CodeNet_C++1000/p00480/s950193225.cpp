#include <iostream>
using namespace std;

long long int ary[150][21]={};
int inp[150];

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>inp[i];
	}
	ary[0][inp[0]]=1;
	for(int mjk=1;mjk<N-1;mjk++){
		for(int i=0;i<=(20-inp[mjk]);i++){
			ary[mjk][i+inp[mjk]]+=ary[mjk-1][i];
		}
		for(int i=20;i>=inp[mjk];i--){
			ary[mjk][i-inp[mjk]]+=ary[mjk-1][i];
		}
	}
	cout<<ary[N-2][inp[N-1]]<<endl;
	return 0;
}