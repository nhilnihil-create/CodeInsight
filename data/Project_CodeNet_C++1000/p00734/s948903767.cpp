#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m), n + m){
		int array_a[200];
		int array_b[200];
		int sum_a = 0;
		int sum_b = 0;
		
		for (int i = 0; i < n; i++){
			scanf("%d", &array_a[i]);
			sum_a += array_a[i];
		}
		for (int i = 0; i < m; i++){
			scanf("%d", &array_b[i]);
			sum_b += array_b[i];
		}
		
		int min = 1145141919;
		int min_a;
		int min_b;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (sum_a - array_a[i] + array_b[j] == sum_b - array_b[j] + array_a[i]){
					if (array_a[i] + array_b[j] < min){
						min = array_a[i] + array_b[j];
						min_a = i;
						min_b = j;
					}
				}
			}
		}
		
		if (min != 1145141919){
			printf("%d %d\n", array_a[min_a], array_b[min_b]);
		}
		else {
			printf("-1\n");
		}
	}
	
	return 0;
}