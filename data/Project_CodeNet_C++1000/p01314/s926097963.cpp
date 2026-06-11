#include<iostream>
using namespace std;
int main(){
	int N;
	while(cin>>N){
		if(N==0){
			break;
		}
		int c,cnt=0;
		for(int i=1;i<N;i++){
			c=i;
			int cn=i+1;
			while(c<N){
				c+=cn;
				cn++;
			}
			if(c==N)cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}