#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;

int r,s,p;

//dpでやったけどうまくいかなかったので解説見て貪欲法で




int main(){
	cin>>n>>k>>r>>s>>p;
	int a=0,b=0;
	int t[k][(n+k-1)/k+1]={};
	int g=(n+k-1)/k+1;
	char h;
	for(int i=0;i<n;i++){
		cin>>h;
		if(h=='r'){
			t[a][b]=3;
		}else if(h=='s'){
			t[a][b]=1;
		}else{
			t[a][b]=2;
		}
		//cout<<a<<" "<<b<<endl;
		if(a>=k-1){
			b++;
			a=0;
		}else{
			a++;
		}
		
	}
	//cout<<"A"<<endl;
	int ans=0;
	for(int i=0;i<k;i++){
		int c=0,e=0;
		while(t[i][c]!=0){
			//cout<<e<<endl;
			if(e!=t[i][c]){
				if(t[i][c]==1){
					ans+=r;
				}else if(t[i][c]==2){
					ans+=s;
				}
				if(t[i][c]==3){
					ans+=p;
				}
				e=t[i][c];
			}else{
				e=0;
			}
			c++;
		}


	}
	cout<<ans<<endl;
}