#include <cstdio>
using namespace std;

int log(int a, int X){
	int n = 0;
	
	while(X > 0){
		X /= a;
		n++;
	}
	
	return n;
}

int main(){
	int a, b, sum;
	
	while(scanf("%d%d", &a, &b) != EOF){
		
		sum = a + b;
		
		printf("%d\n", log(10, sum));
	}
	
	return 0;
}