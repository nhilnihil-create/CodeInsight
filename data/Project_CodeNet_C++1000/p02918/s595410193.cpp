#include<iostream>
#include<string>
using namespace std;
int main(){
	int N,K;
	cin>>N>>K;
	string str;
	cin>>str;
	int l=str.length();
	int hL=0,hR=0,mL=0,mR=0,happy=0;
	for(int i=0;i<l;i++){
		if(str[i]=='R'){
			if(i==0){
				hR+=1;
			}
			else if(str[i]!=str[i-1]){
				mR+=1;
			}
			else if(str[i]==str[i-1]){
				happy+=1;
			}

		}
		if(str[i]=='L'){
			if(i==0)
				hL+=1;
			else if(str[i]!=str[i-1])
				mL+=1;
			else if(str[i]==str[i-1])
				happy+=1;

		}
	}
	if(str[l-1]=='R'){
		mR-=1;hR+=1;
	}
	else{
		mL-=1;hL+=1;
	}
	//cout<<hL<<" "<<hR<<" "<<mL<<" "<<mR<<" "<<happy<<endl;
	int big=mL>mR?mL:mR;
	if(mL!=mR){
		if(K<=big)
		  happy=happy+K*2;
		if(K>big)
			happy+=big*2;
	}
	else if(mL==mR){
		if(K<=big)
			happy+=K*2;
		if(K>big)
			happy+=big*2+1;

	}
	cout<<happy<<endl;

	return 0;
}