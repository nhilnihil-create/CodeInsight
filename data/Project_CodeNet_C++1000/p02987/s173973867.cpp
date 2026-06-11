#include <bits/stdc++.h>
using namespace std;
int main(){
	char s[4];
	cin>>s;
	int sb[4]={0,1,2,3};
	for(int i=0;i<3;i++) {
		if(i!=0){
			if(sb[i]>sb[i-1]+1){
				sb[i]=sb[i-1]+1;
			}
		}
		for(int j=i+1;j<4;j++){
			if(s[i]==s[j]) sb[j]=sb[i];
		}
	}
	int a=0,b=0;
	for(int i=0;i<4;i++) {
		if(sb[i]==0) a++;
		else if(sb[i]==1) b++;
	}
	if(a==2&&b==2) cout<<"Yes";
	else cout<<"No";
	cout<<"\n";
	return 0;
}