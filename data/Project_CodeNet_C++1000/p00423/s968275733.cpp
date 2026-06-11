#include <cstdio>
using namespace std;

void opera(int n);
int main(void)
{
	int n;
	
	
	while (1){
		scanf("%d", &n);
		if (n == 0){
			break;
		}
		else {
			opera(n);
		}
	}
	
	return (0);
}

void opera(int n)
{
	int a_sum = 0;
	int b_sum = 0;
	
	
	for (int i = 0; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		
		if (a == b){
			a_sum += a;
			b_sum += b;
		}
		else if (a > b){
			a_sum = a_sum + a + b;
		}
		else {
			b_sum = b_sum + a + b;
		}
	}
	
	printf("%d %d\n", a_sum, b_sum);
}