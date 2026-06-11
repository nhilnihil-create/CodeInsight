#include <iostream>
using namespace std;
int ary[60],res[40];
int main(){
	int N;
	for(int i=1;i<=51;i++){
		cin>>ary[i];
		if(cin.eof()){
			N=i-1;
			break;
		}
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				for(int l=0;l<10;l++){
					res[i+j+k+l]++;
				}
			}
		}
	}
	for(int i=1;i<=N;i++){
		if(ary[i]>=0&&ary[i]<=36)cout<<res[ary[i]]<<endl;
		else cout<<0<<endl;
	}
	return 0;
}