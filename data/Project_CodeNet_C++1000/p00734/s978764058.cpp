#include<iostream>

using namespace std;
int main(){
	int n,m;
	while(cin>>n>>m&&n&&m){
		int d1[100];
		int d2[100];
		int s1=0,s2=0;
		for(int i=0;i<n;i++){cin>>d1[i];s1+=d1[i];}
		for(int i=0;i<m;i++){cin>>d2[i];s2+=d2[i];}
		int a1=-1,a2=-1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if((s1-d1[i]+d2[j]==s2-d2[j]+d1[i])){
					if(a1==-1 || a1+a2>d1[i]+d2[j]){
						a1=d1[i];
						a2=d2[j];
					}
				}
			}
		}
		if(a1!=-1)cout<<a1<<" "<<a2<<endl;
		else cout<<-1<<endl;
	}
}