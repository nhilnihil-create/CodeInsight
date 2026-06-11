#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		char mcxi_a[128];
		char mcxi_b[128];
		int sum = 0;
		scanf("%s %s", mcxi_a, mcxi_b);
		
		int i = 0;
		while (mcxi_a[i] != '\0'){
			switch (mcxi_a[i]){
				case 'i':
				if (i > 0 && mcxi_a[i - 1] >= '2' && mcxi_a[i - 1] <= '9'){
					sum += mcxi_a[i - 1] - '0';
				}
				else {
					sum += 1;
				}
				break;
				
				case 'x':
				if (i > 0 && mcxi_a[i - 1] >= '2' && mcxi_a[i - 1] <= '9'){
					sum += (mcxi_a[i - 1] - '0') * 10;
				}
				else {
					sum += 10;
				}
				break;
				
				case 'c':
				if (i > 0 && mcxi_a[i - 1] >= '2' && mcxi_a[i - 1] <= '9'){
					sum += (mcxi_a[i - 1] - '0') * 100;
				}
				else {
					sum += 100;
				}
				break;
				
				case 'm':
				if (i > 0 && mcxi_a[i - 1] >= '2' && mcxi_a[i - 1] <= '9'){
					sum += (mcxi_a[i - 1] - '0') * 1000;
				}
				else {
					sum += 1000;
				}
				break;
			}
			
			i++;
		}
		
		i = 0;
		while (mcxi_b[i] != '\0'){
			switch (mcxi_b[i]){
				case 'i':
				if (i > 0 && mcxi_b[i - 1] >= '2' && mcxi_b[i - 1] <= '9'){
					sum += mcxi_b[i - 1] - '0';
				}
				else {
					sum += 1;
				}
				break;
				
				case 'x':
				if (i > 0 && mcxi_b[i - 1] >= '2' && mcxi_b[i - 1] <= '9'){
					sum += (mcxi_b[i - 1] - '0') * 10;
				}
				else {
					sum += 10;
				}
				break;
				
				case 'c':
				if (i > 0 && mcxi_b[i - 1] >= '2' && mcxi_b[i - 1] <= '9'){
					sum += (mcxi_b[i - 1] - '0') * 100;
				}
				else {
					sum += 100;
				}
				break;
				
				case 'm':
				if (i > 0 && mcxi_b[i - 1] >= '2' && mcxi_b[i - 1] <= '9'){
					sum += (mcxi_b[i - 1] - '0') * 1000;
				}
				else {
					sum += 1000;
				}
				break;
			}
			
			i++;
		}
		
		if (sum / 1000 > 0){
			if (sum / 1000 >= 2 && sum / 1000 <= 9){
				printf("%d", sum / 1000);
			}
			printf("m");
		}
		sum %= 1000;
		if (sum / 100 > 0){
			if (sum / 100 >= 2 && sum / 100 <= 9){
				printf("%d", sum / 100);
			}
			printf("c");
		}
		sum %= 100;
		if (sum / 10 > 0){
			if (sum / 10 >= 2 && sum / 10 <= 9){
				printf("%d", sum / 10);
			}
			printf("x");
		}
		sum %= 10;
		if (sum > 0){
			if (sum >= 2 && sum <= 9){
				printf("%d", sum);
			}
			printf("i");
		}
		puts("");
	}
	
	return 0;
}