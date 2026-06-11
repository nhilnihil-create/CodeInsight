#include <cstdio>
using namespace std;

int main(){
		int n;scanf("%d",&n);
		char str[n];
		scanf("%s",str);
		int count=0;
		for(int i=0;i<=n-1-2;i++){
				if(str[i]=='A'){
						if(str[i+1]=='B'){
								if(str[i+2]=='C'){
										count++;
									}
							}
					}
			}
		printf("%d",count);	
	}
