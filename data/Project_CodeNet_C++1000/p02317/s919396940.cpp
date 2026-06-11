#include <stdio.h>
#include <stack>
#include <math.h>

using namespace std;


int main(){

	int n,tmp;
	scanf("%d",&n);

	int L[n],length = 0;

	for(int i=0; i < n; i++){
		scanf("%d",&tmp);

		if(i == 0){
			L[0] = tmp;
		}else{
			if(L[length] < tmp){
				length++;
				L[length] = tmp;
			}else{
				for(int k = 0; k <= length; k++){
					if(L[k] >= tmp){
						L[k] = tmp;
						break;
					}
				}
			}
		}
	}

	printf("%d\n",length+1);

    return 0;
}