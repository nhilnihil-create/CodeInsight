#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,m;scanf("%d %d",&n,&m);
	int WA[n+2];
	int AC[n+2];
	int num,ans1(0),ans2(0);
	string test;
	for(int i=0;i<=n;i++){
			WA[i]=0;
			AC[i]=0;
		}
	for(int i=1;i<=m;i++){
			cin>>num>>test;
			if(AC[num]==1)continue;
			if(test == "AC"){
					AC[num]=1;
					ans1++;
					ans2 += WA[num];
				}
			else if(test == "WA"){
					WA[num]++;
				}	
		}
	printf("%d %d",ans1,ans2);	
	return 0;
	} 
