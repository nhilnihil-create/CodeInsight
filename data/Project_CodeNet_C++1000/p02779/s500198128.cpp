#include <cstdio>
#include <set>
using namespace std;

int main(){
	int N,i,flag;
	scanf("%d",&N);
	set<int> a;
	for(i=0;i<N;i++){
		scanf("%d",&flag);
		a.insert(flag);
	}
    if(N==a.size())
        printf("YES\n");
    else
	    printf("NO\n");    
	return 0;
}
