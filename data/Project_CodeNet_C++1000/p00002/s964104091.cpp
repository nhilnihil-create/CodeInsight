#include <iostream>
using namespace std;
int digit(int num){
	int cnt=0;
	while(num>0){
		num/=10;
		cnt++;
	}
	return cnt;
}

int main(){
	int A[210],B[210];
	int N;
	for(int i=1;i<=200;i++){
		cin>>A[i]>>B[i];
		if(cin.eof()){
			N=i-1;
			break;
		}
	}
	for(int i=1;i<=N;i++){
		cout<<digit(A[i]+B[i])<<endl;
	}
	return 0;
}