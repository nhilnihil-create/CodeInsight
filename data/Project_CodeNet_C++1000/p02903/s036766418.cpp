#include<cstdio>
#include<iostream>
using namespace std;
int n,m,a,b;
int main(){
	scanf("%d%d%d%d",&n,&m,&b,&a);
	if(a>n/2||b>m/2){printf("-1");return 0;}
	if(!a&&!b){
		for(int i=1;i<=n;i++,printf("\n"))
		for(int j=1;j<=m;j++) printf("1");return 0;
	}
	if(!b){
		for(int j=1;j<=a;j++,printf("\n"))
		for(int i=1;i<=m;i++)printf("1"); 
		
		for(int j=a+1;j<=n;j++,printf("\n"))
		for(int i=1;i<=m;i++)printf("0"); 
		return 0; 
	}
	if(!a){
		
		for(int j=1;j<=n;j++,printf("\n")){
			for(int i=1;i<=b;i++)printf("1"); 
		
		for(int i=b+1;i<=m;i++)printf("0"); 
		}
		
		return 0; 
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i<=a&&j<=b) cout<<"1";
			else if(i>a&&j>b) cout<<"1";
			else cout<<"0";
		}cout<<endl;
	}	
}