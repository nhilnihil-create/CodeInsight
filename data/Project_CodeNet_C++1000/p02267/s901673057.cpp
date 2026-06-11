#include<iostream>
using namespace std;
int main(){
	int n,S[10000],q,T[500],c=0,i,i2,toread,cnt;
	cin>>n;
	for(i=0;i<n;i++)cin>>S[i];
	cin>>q;
	for(i=0;i<q;i++)cin>>T[i];
	for(i=0;i<n;i++){
		for(i2=0;i2<n;i2++){
			if(S[i]<S[i2]){
				toread=S[i];
				S[i]=S[i2];
				S[i2]=toread;
			}
		}
	}
	for(i=0;i<q;i++){
		cnt=0;
		toread=n;
		while(toread>1){
			if(toread%2==0)toread/=2;
			else toread=(toread+1)/2;
			if(S[(toread-1)+cnt]<T[i])cnt+=toread;
			else if(S[(toread-1)+cnt]==T[i]){
				c++;
				break;
			}
		}
	}
	cout<<c<<endl;
}