#include <cstdio>
 
using namespace std;
int a[34]={0, 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
int K;
int main(){
	scanf("%d",&K);
    printf("%d",a[K]);
	return 0;
}