#include<bits/stdc++.h>
using namespace std;
int main(){
	while(1){
		int n,cnt,hantei=0;
		cin>>n;
		if(n==0)
			break;
		for (int i=n+1;i<=2*n;i++){
			cnt=0;
			for(int j=2;j*j<=i;j++){
				if(i%j==0){
					cnt++;}
			}
			if(cnt==0)
				hantei++;
		}
		cout<<hantei<<endl;	
	}
		return 0;
}
