#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <algorithm>
using namespace std;

int n,ten[1003],ans;

int main(){
while(1){
	
	
	scanf("%d",&n);
	if(n == 0)break;
	for(int i = 0;i < n;i++){
		scanf("%d",&ten[i]);
	}
	
	ans = abs(ten[0]-ten[1]);
	
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j++){
			ans = min(ans,abs(ten[i]-ten[j]));
		}
	}
	
	printf("%d\n",ans);
	
}

return 0;

} 
	
	
	
